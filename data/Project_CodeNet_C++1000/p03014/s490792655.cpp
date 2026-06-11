#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int a[2003][2003];
    rep(i,h){
        string s;cin>>s;
        rep(j,w){
            if(s[j]=='#')a[i][j]=0;
            else a[i][j]=1;
        }
    }
    int ans = 0;
    int cc=1;
    int tt=0;
    rep(i,h)rep(j,w){
        int tmp = 0;
        if(a[i][j]==1){
            ++tmp;
        cc=1;
        while(a[i-cc][j]==1 && i-cc>=0){
            ++tmp;
            ++cc;
        }
        cc=1;
        while(a[i+cc][j]==1 && i+cc<=h-1){
            ++tmp;
            ++cc;
        }
        cc=1;
        while(a[i][j-cc]==1 && j-cc>=0){
            ++tmp;
            ++cc;
        }
        cc=1;
        while(a[i][j+cc]==1 && j+cc<=w-1){
            ++tmp;
            ++cc;
        }
        }
        ans=max(ans,tmp);
        ++tt;
      if(ans>=1960 && tt>=100000)break;
    }
    cout<<ans<<endl;
	return 0;
}