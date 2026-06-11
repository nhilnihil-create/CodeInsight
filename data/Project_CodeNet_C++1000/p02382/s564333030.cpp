#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    rep(i,n){
        cin>>x[i];
    }
    rep(i,n){
        cin>>y[i];
    }
    double p1=0.0;
    rep(i,n){
        p1+=abs(x[i]-y[i]);
    }
    double p2=0.0;
    rep(i,n){
        p2+=pow(abs(x[i]-y[i]), 2);
    }
    p2 = pow(p2,0.5);
    double p3=0.0;
    rep(i,n){
        p3+=pow(abs(x[i]-y[i]), 3);
    }
    p3 = pow(p3, 1.0/3);
    double pm=abs(x[0]-y[0]);
    rep(i,n){
        if(pm<abs(x[i]-y[i]))pm=abs(x[i]-y[i]);
    }
    cout<<fixed<<setprecision(10)<<p1<<endl<<p2<<endl<<p3<<endl<<pm<<endl;
    return 0;
}
