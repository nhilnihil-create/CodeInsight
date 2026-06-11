#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int DP(vector<vector<bool>> Gragh)
{
    vector<vector<int>> DP(Gragh.size(),vector<int>(Gragh[0].size(),1e9));
    if(Gragh[0][0]) DP[0][0] = 0; // 白ならば
    else DP[0][0] = 1; // 黒ならば

    for(int i=0;i<Gragh.size()-1;i++)
    {
        if(Gragh[i+1][0] && Gragh[i][0])
        {
            DP[i+1][0] = DP[i][0];
        }
        if(Gragh[i+1][0] && !Gragh[i][0])
        {
            DP[i+1][0] = DP[i][0];
        }
        if(!Gragh[i+1][0] && Gragh[i][0])
        {
            DP[i+1][0] = DP[i][0] + 1;
        }
        if(!Gragh[i+1][0] && !Gragh[i][0])
        {
            DP[i+1][0] = DP[i][0];
        }
    }
    for(int i=0;i<Gragh[0].size()-1;i++)
    {
        if(Gragh[0][i+1] && Gragh[0][i])
        {
            DP[0][i+1] = DP[0][i];
        }
        if(Gragh[0][i+1] && !Gragh[0][i])
        {
            DP[0][i+1] = DP[0][i];
        }
        if(!Gragh[0][i+1] && Gragh[0][i])
        {
            DP[0][i+1] = DP[0][i] + 1;
        }
        if(!Gragh[0][i+1] && !Gragh[0][i])
        {
            DP[0][i+1] = DP[0][i];
        }    
    }

    for(int i=0;i<Gragh.size()-1;i++)
    {
        for(int j=0;j<Gragh[0].size()-1;j++)
        {
            if(Gragh[i+1][j] && Gragh[i][j+1])
            {
                if(Gragh[i+1][j+1])
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]);
                }
                else
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1])+1;
                }
            }
            if(Gragh[i+1][j] && !Gragh[i][j+1])
            {
                if(Gragh[i+1][j+1])
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]);
                }
                else
                {
                    DP[i+1][j+1] = min(DP[i+1][j]+1,DP[i][j+1]);
                }
            }
            if(!Gragh[i+1][j] && Gragh[i][j+1])
            {
                if(Gragh[i+1][j+1])
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]);
                }
                else
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]+1);
                }
            }
            if(!Gragh[i+1][j] && !Gragh[i][j+1])
            {
                if(Gragh[i+1][j+1])
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]);
                }
                else
                {
                    DP[i+1][j+1] = min(DP[i+1][j],DP[i][j+1]);
                }
            }
        }
    }

    return DP[Gragh.size()-1][Gragh[0].size()-1];
}

int main()
{
    int H,W;
    cin >> H >> W;

    vector<vector<bool>> Gragh(H,vector<bool>(W));
    // 白ならばtrue; 黒ならばfalse;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            char s;
            cin >> s;

            if(s=='#') Gragh[i][j]=false;
            if(s=='.') Gragh[i][j]=true;
        }
    }

    int ans = DP(Gragh);

    cout << ans << endl;

    return 0;
}