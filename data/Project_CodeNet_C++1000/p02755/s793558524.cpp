#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int a,b;
    cin>>a>>b;
    ll ans=0;
    if(12.5*a+12.5<=10.0*b || 10.0*b+10.0<=12.5*a){
        cout<<-1<<endl;
        return 0;
    }else{
        double c=max(12.5*a,10.0*b);
        if(c==(int)c){
            ans=c;
        }else{
            ans=c/1+1;
        }
        cout<<ans<<endl;
        return 0;
    }
}
