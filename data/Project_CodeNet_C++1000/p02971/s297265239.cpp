#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
    int max1=0,max2=0;
    int x,y;
    rep(i,n){
        if(max1<v[i]){
            max2=max1;
            y=x;
            max1=v[i];
            x=i;
        }
        else if(max2<v[i]){
            max2=v[i];
            y=i;
        }
    }
    rep(i,n){
        if(i==x){
            cout<<max2<<endl;
        }
        else{
            cout<<max1<<endl;
        }
    }
}