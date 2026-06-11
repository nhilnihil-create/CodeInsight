#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int H,W,K;
char c[6][6];

int main()
{
    int i, j,ans=0;
    cin >> H >> W >> K;
    rep0(i, H) rep0(j,W) cin >>c[i][j];

    int bh,bw,count;
    rep0(bh,1<<H) rep0(bw,1<<W){
        count=0;
        rep0(i,H)rep0(j,W){
            if(((1<<i)&bh) && ((1<<j)&bw) && c[i][j]=='#')
            count++;
        }
        //cout<<count<<endl;
        if(count==K)ans++;
    }

    cout << ans << endl;
    return 0;
}