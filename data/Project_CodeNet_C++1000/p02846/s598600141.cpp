#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define eb emplace_back
#define mp make_pair
using namespace std;
ll t1,t2,a1,a2,b1,b2;
int main(){
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(t1*a1+t2*a2==t1*b1+t2*b2){
        cout<<"infinity"<<endl;
    }else{
        ll dis1=t1*a1-t1*b1;
        ll dis2=dis1+t2*a2-t2*b2;
        if(dis1>0&&dis2>0||dis1<0&&dis2<0){
            cout<<0<<endl;
        }else{
            ll dis=t1*(a1-b1)+t2*(a2-b2);
            if(dis1<0){
                swap(a1,b1),swap(a2,b2);
            }
            dis=abs(dis),dis1=abs(dis1);
            cout<<dis1/dis*2+(dis1%dis!=0)<<endl;
        }
    }
    return 0;
}