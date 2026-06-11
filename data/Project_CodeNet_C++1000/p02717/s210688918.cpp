#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z,t;
    cin>>x>>y>>z;
    
    t=x;
    x=y;
    y=t;
    
    t=x;
    x=z;
    z=t;
    
    cout<<x<<' '<<y<<' '<<z<<endl;
}