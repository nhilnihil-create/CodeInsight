#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int MAXN=2e5+100;
const ll MOD=1e9+7;
struct node{
    int x,y;
}p[MAXN];
int main()
{
    ios;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    int maxn1=-1e9,maxn2=-1e9;
    int minn1=1e9,minn2=1e9;
    for(int i=1;i<=n;i++){
        maxn1=max(maxn1,p[i].x+p[i].y);
        minn1=min(minn1,p[i].x+p[i].y);
        maxn2=max(maxn2,p[i].x-p[i].y);
        minn2=min(minn2,p[i].x-p[i].y);
    }
    int ans1=maxn1-minn1;
    int ans2=maxn2-minn2;
    int ans3=-ans2;
    cout<<max(ans1,max(ans2,ans3))<<'\n';
    return 0;
}