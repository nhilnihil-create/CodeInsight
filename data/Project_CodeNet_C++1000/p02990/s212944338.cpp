#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

vector<lint> factorial(2001);
const lint mod=1000000007;

lint inv(lint a) {
    lint b = mod, u = 1, v = 0;
    while(b){
        lint t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=mod; 
    if(u<0)u+=mod;
    return u;
}


//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    factorial[0]=1;
    for(int i=1;i<=2000;i++)factorial[i]=factorial[i-1]*i%mod;
    lint n,k,r,bunsi,bunbo;cin>>n>>k;
    r=n-k;
    for(int i=1;i<=k;i++){
        lint ans;
        if(i-1>r)ans=0;
        else{
            bunsi=factorial[k-1]*factorial[r+1]%mod;
            bunbo=factorial[k-i]*factorial[i-1]%mod;
            bunbo=bunbo*factorial[r+1-i]%mod;
            bunbo=bunbo*factorial[i]%mod;
            ans=bunsi*inv(bunbo)%mod;
        }
        cout<<ans<<endl;
    }
    
}
