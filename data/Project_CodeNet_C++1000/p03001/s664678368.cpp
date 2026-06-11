#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    double ans=w*h/2;
    printf("%.9f",ans);
    if(w/2==x&&h/2==y) cout<<" 1";
    else cout<<" 0";
}