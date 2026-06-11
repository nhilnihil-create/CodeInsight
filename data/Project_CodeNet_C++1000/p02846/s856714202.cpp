#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    ll da1=t1*a1,db1=t1*b1,da2=da1+t2*a2,db2=db1+t2*b2;
    if(da2==db2){
        cout<<"infinity"<<endl;
        return 0;
    }
    if((da1>db1&&da2>db2)||(da1<db1&&da2<db2)){
        cout<<0<<endl;
        return 0;
    }
    ll an=2*(abs(da1-db1)/(ll)abs(da2-db2))+1;
    if(abs(da1-db1)%(ll)abs(da2-db2)==0)an--;
    cout<<an<<endl;
}

    







