#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define in insert
#define pi 3.14159265358979323846
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define repr(i,a,b) for(int i = b ; i > a ; i--)
  
long long fact(long long a, long long b){
    int r= max(a, b);
    int v= min(a, b);
    int l=1;
    // if(v==0)
    for(int i=r+1; i<=a+b; i++){
        l*=i;
    }
    for(int i=v; i>=2; i--){
        l/=i;
    }
    return l;
}

int gcd(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

int powr(int a) { 
    int var=1;
    for(int i=0; i<a; i++){
        var*=2;
    }
    return var;
}

signed main(){   
    fast;
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i,0,n){
        cin >> a[i];
        // s.insert({{a[i],1}, a[i]});
    }
    int l = 1 , r = 10000000000;
    while(l+1<r){
        int mid=(l+r)/2, ct=0;
        rep(i,0,n){
            ct+=(a[i]-1)/mid;
        }
        if(ct<=k){
            r=mid;
        }
        else
            l=mid+1;
    }
    int ct=0;
    rep(i,0,n)
        ct += (a[i]-1)/l;
    if(ct<=k) cout << l;
    else cout << r;
}