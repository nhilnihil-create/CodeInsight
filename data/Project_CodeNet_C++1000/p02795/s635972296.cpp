#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int h,w,n,sum=0;
    cin>>h>>w>>n;
    if(h>=w){
        rep(i,w){
            sum+=h;
            if(sum>=n){
                cout<<i+1;
                return 0;
            }
        }
    }
    else{
        rep(i,h){
            sum+=w;
            if(sum>=n){
                cout<<i+1;
                return 0;
            }
        }
    }
}