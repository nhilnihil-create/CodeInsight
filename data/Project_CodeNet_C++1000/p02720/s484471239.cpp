#include<bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define si size()
#define mp make_pair 
#define mt make_tuple
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
 
#define ask(i,m,n) for(int i=m;i<n;i++)
#define anket ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
#define endl "\n"
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout<<a<<" "<<b<<"\n"
#define o3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
using namespace std;
 
#define prime1 1000000009
#define prime2 998244353
 
lli modadd(lli n,lli m , lli mod){
    lli sum = ((n+m)%mod+mod)%mod;
    return sum;
}
 
lli modsub(lli n,lli m,lli mod){
    lli diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}
 
lli modpro(lli n,lli m, lli mod){
    lli pro = ((n*m)%mod+mod)%mod;
    return pro;
}
 
lli powmod(lli x,lli y,lli mod){
    x %= mod;
    y %= mod;
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x,mod);
        y = y >> 1;
        x = modpro(x , x,mod);
    }
    return res;
}
 
lli moddiv(lli n,lli m,lli mod){
    //return n/m mod (mod) or n*(m)^-1 mod (mod)
    lli a = powmod(m,mod-2,mod);
    //this is because of fermats thm i.e. a^-1 = a^p-2 mod(p) check
    //multiplying p on both sides
    lli res = modpro(a,n,mod);
    return res;
}
 
vector<lli> prefix_function(string s) {
    lli n = (lli)s.length();
    vector<lli> pi(n);
    for (lli i = 1; i < n; i++) {
        lli j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
vector<lli> z_function(string s) {
    lli n = (lli) s.length();
    vector<lli> z(n);
    for (lli i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
 
/*
1.to give bezouts coef
2.for non negative integers
3.all solutions can be obtained by x0 - b/g and y0 + a/g
4.can be used for computing the multiplicative inverse. Co-efficient of a is
the multiplicative inverse.
*/
pair<lli,lli> bez_coef(lli a,lli b){
    lli s0=1,s1=0,t0=0,t1=1;
    lli r,q;
    
    if(a<b){
        swap(a,b);
        swap(s0,t0);
        swap(s1,t1);
    }
    
    lli c1,c2;
    
    while(1){
        r = a%b;
        q = a/b;
        a=b;
        b=r;
        if(r==0){
            return mp(s1,t1);
        }
        c1=s0;
        c2=s1;
        s0=s1;
        s1 = c1 - q*c2;
        c1 = t0;
        c2= t1;
        t0=t1;
        t1 = c1 - q*c2;
    }
}
 
/*
1. to return the phi(n).
2. sum of phi of all divisors of n is n.
3. can be used to find index such  that raised to it gives remainder 1.
*/
lli phi(lli n) {
    lli result = n;
    for (lli i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
 
/*
1.to get the phi of all numbers from 1 to n
*/
vector<lli> phi_1_to_n(lli n) {
    vector<lli> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (lli i = 2; i <= n; i++)
        phi[i] = i;
 
    for (lli i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (lli j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
} 
 
vector<bool> is_prime_array(lli n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (lli i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (lli j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
 
class pr{ 
    public: 
    lli parent; 
    lli rank; 
}; 
 
lli find(pr subs[], lli i){ 
    if (subs[i].parent != i) 
        subs[i].parent = find(subs, subs[i].parent); 
    return subs[i].parent; 
} 
 
void Union(pr subs[], lli x, lli y){ 
    lli xroot = find(subs, x); 
    lli yroot = find(subs, y); 
    if (subs[xroot].rank < subs[yroot].rank){
        subs[xroot].parent = yroot; 
    }
    else if (subs[xroot].rank > subs[yroot].rank){
        subs[yroot].parent = xroot;
    }
    else{ 
        subs[yroot].parent = xroot; 
        subs[xroot].rank++; 
    } 
} 


int main() {
    anket;
    lli k;
    cin>>k;
    vector<lli> a;
    for(int i=1;i<=9;i++){
        a.pb(i);
    }
    int c=0,b;
    while(a.size()<k){
        b = a[c]%10;
        if(b==0){
            a.pb(10*a[c]);
            a.pb(10*a[c]+1);

        }
        else if(b==9){
            a.pb(10*a[c]+8);
            a.pb(10*a[c]+9);

        }
        else{
            a.pb(10*a[c]+b-1);
            a.pb(10*a[c]+b);
            a.pb(10*a[c]+b+1);
        }
        c++;
    }
    sort(a.begin(),a.end());
    o1(a[k-1]);
    return 0;
}