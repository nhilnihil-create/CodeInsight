#include<iostream>
#define ll long long
using namespace std;
int main(){
    ll t[2],a[2],b[2];
    cin>>t[0]>>t[1];
    cin>>a[0]>>a[1];
    cin>>b[0]>>b[1];
    ll ans=0;
    if(a[0]*t[0]+a[1]*t[1]==b[0]*t[0]+b[1]*t[1]){
        if(a[0]*t[0]!=b[0]*t[0]){
            cout<<"infinity"<<endl;
            return 0;
        }
        else ans=0;
    }
    else{
        ll x1=a[0]*t[0];
        ll x2=a[1]*t[1];
        ll y1=b[0]*t[0];
        ll y2=b[1]*t[1];
        if(a[0]*t[0]+a[1]*t[1]>b[0]*t[0]+b[1]*t[1]){
            if(a[0]*t[0]>=b[0]*t[0])ans=0;
            else{
                ans=1+(y1-x1)/(x1+x2-y1-y2)+(y1-x1)/(x1+x2-y1-y2);
                if((y1-x1)%(x1+x2-y1-y2)==0)ans--;
            }
        }
        else{
            if(a[0]*t[0]<=b[0]*t[0])ans=0;
            else{
                ans=1+(x1-y1)/(y1+y2-x1-x2)+(x1-y1)/(y1+y2-x1-x2);
                if((x1-y1)%(y1+y2-x1-x2)==0)ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}