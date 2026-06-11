#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main(){
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(6)<<(double)w*h/2.0<<" ";
    if(x==w/2.0&&y==h/2.0){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}