#include <bits/stdc++.h>
#define name "bai1"
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
int m,d;
int main()
{
    //freopen(name".inp", "r", stdin);
   // freopen(name".out", "w", stdout);
    cin >> m >> d;
    int ans=0;
    while(d){
        int a=d/10;
        int b=d%10;
        int t=a*b;
        if(t!=0 && t<=m && a>=2 && b>=2)++ans;
        --d;
    }
    cout <<ans;
    return 0;
}
