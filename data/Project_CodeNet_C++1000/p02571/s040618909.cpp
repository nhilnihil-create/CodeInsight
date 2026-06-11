/***
  *  بسم الله الرحمن الرحيم
  *
  * author : Ahmed al mohammed
  *
***/

#include<bits/stdc++.h>
#define P push
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define pf push_front
#define PQ priority_queue
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define  lp(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define  up(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define hurry ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

ll pw(ll x ,ll os)
{
    if(os==0)return 1;
    ll z=pw(x,os/2);
    if(os%2)return z*z*x;
    else return z*z;
}

void sieve(){
   ll n=1e5+1;
   int a[n+5]={};
   for(ll i=2;i*i<=n;i++){
    if(!a[i])
    for(ll j=i*i;j<=n;j+=i){
        a[j]=1;
    }
   }
   for(ll i=2;i<=n;i++)
    if(!a[i])cout<<i;
}


long long Cnr(long long n,long long r){
    r=min(r,n-r);
    long long ans=1;
    for(long long i=1 ; i<=r ; i++){
        ans*=(n--);
        ans/=i;
    }
    return ans;
}

bool isprime(ll x){
for(ll i=2;i*i<=x;i++){
    if((x%i)==0)return false;
}
return true;
}
void run_case(){
 string s,t;cin>>s>>t;
 int c=0,mx=-1e8;
 for(int i=0;i<t.size();i++){
    for(int j=i;j<s.size();){
        int h=0;c=0;
        while(j<s.size()&&h<t.size()){
            int di=t.size()-h,dij=s.size()-j;
            if(t[h]==s[j]&&dij>=di)c++;
            h++,j++;
        }
        mx=max(mx,c);
    }
 }
 cout<<t.size()-mx;
}

int main(){
    hurry
    int tests=1;
  // cin>>tests;
    while(tests--)
        run_case();

    return 0;
}
