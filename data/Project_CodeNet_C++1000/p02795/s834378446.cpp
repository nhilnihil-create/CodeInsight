#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int h,w,n;
    cin>>h>>w>>n;
    if(n%max(h,w)!=0)cout<<n/max(h,w)+1<<endl;
    else cout<<n/max(h,w)<<endl;
    return 0;
}