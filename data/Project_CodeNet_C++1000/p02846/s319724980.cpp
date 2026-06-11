#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 

int main(void){
    ll t1,t2;
    ll a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    ll v1=b1-a1;
    ll v2=b2-a2;
    ll p=v1*t1;
    ll q=v2*t2;
    if(p+q==0)cout<<"infinity"<<endl;
    else{
        if(p<0){
            if(p+q<0)cout<<0<<endl;
            else{
                ll x=-p/(p+q);
                if((-p)%(p+q)==0)cout<<2*x<<endl;
                else cout<<2*x+1<<endl;
            }
        }
        else{
            if(p+q>0)cout<<0<<endl;
            else{
                ll x=-p/(p+q);
                if(p%(p+q)==0)cout<<2*x<<endl;
                else cout<<2*x+1<<endl;
            }
        }
    }
    return 0;
}