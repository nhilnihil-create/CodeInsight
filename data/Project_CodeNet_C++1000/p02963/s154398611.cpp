#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    ll s;
    cin>>s;
    int x=0,y=0;
    int n=1e9;
    x=(n-s%n)%n;
    y=ceil((double)s/n);
    cout<<"0 0 1000000000 1 "<<x<<" "<<y<<endl;
}