#include<bits/stdc++.h>
using namespace std;
int main(){
    long long h,w,x,y;
    cin>>h>>w>>x>>y;
    cout<<h*w/2<<".";
    if(h*w%2)cout<<"500000000000"<<endl;
    else cout<<"000000000000"<<endl;
    if(x*2==h && y*2==w)cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
