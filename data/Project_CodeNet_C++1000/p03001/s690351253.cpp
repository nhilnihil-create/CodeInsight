#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

int main(){
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(6)<<w*h/2.0<<' ';
    if(w/2 == x && h/2 == y){
        cout<<1;
    }
    else cout<<0;
}