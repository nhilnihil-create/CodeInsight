#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)

int H, W, M;
int numH[300010], numW[300010];
vector<int> vW[300010];
vector<int> vH[300010];

signed main()
{
    cin >> H >> W >> M;
    rep(i, M)
    {
        int h, w;
        cin >> h >> w;
        numH[h]++;
        numW[w]++;
        vW[w].push_back(h);
    }

    int maxW = -1;
    for(int i = 1; i <= 300000; i++)
        maxW = max(maxW, numW[i]);

    int num = 0;
    for(int i = 1; i <= 300000; i++)if(numW[i] == maxW)
    {
        num++;
        for(auto e : vW[i])vH[e].push_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= 300000; i++)
    {
        int tmp;
        if(vH[i].size() == num)tmp = numH[i] + maxW - 1;
        else tmp = numH[i] + maxW;
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
