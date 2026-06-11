#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n;
    double ans=0;
    cin>>n;
    rep(i,n){
        double a;
        cin>>a;
        ans+=1/a;
    }
    ans=1/ans;
    printf("%.10f",ans);
}