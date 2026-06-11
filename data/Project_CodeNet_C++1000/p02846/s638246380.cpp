#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t1,t2,a1,a2,b1,b2;
    //cin>>t;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    
    if((a1*t1 + a2*t2) == (b1*t1 + b2*t2)){
        cout<<"infinity\n";
    }
    else{
        if((b1*t1+b2*t2)<(a1*t1+a2*t2)){
            swap(a1,b1);
            swap(a2,b2);
        }
        
        ll q1=(a1*t1-b1*t1),q2=((b2*t2+b1*t1)-(a1*t1+a2*t2));
        ll ans=q1/q2;
        if(b1>a1)
            cout<<0;
        else if(q1%q2==0)
            cout<<ans*2;
        else
            cout<<ans*2+1;
        cout<<endl;
    }
    return 0;
}

