#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using Lint=long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    Lint t1,t2; cin>>t1>>t2;
    Lint a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;

    if(a1*t1+a2*t2==b1*t1+b2*t2){
        cout<<"infinity"<<endl;
        return 0;
    }

    if(a1*t1+a2*t2<b1*t1+b2*t2){
        swap(a1,b1);
        swap(a2,b2);
    }

    a1*=t1; a2*=t2;
    b1*=t1; b2*=t2;

    if(a1>b1){
        cout<<0<<endl;
        return 0;
    }
    if(a1==b1){
        cout<<1<<endl;
        return 0;
    }
    Lint v1=a1-b1;
    Lint v2=a2-b2;
    Lint ans=(-v1)/(v1+v2)*2+((-v1)%(v1+v2)!=0);
    cout<<ans<<endl;
    return 0;
}