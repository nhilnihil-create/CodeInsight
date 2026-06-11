#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    int h,k,w;
    cin>>h>>w>>k;
    vector<vector <int> > c(h,vector<int> (4));
    rep(i,h)
    {
        rep(j,w)
        {
            char s;
            cin>>s;
            if(s=='#') c[i][j]=1;
            else c[i][j]=0;
        }
    }

    int ans =0;

    int n = h+w;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) 
    {
        int sum=0;
        
        vector<int> S;
        S.push_back(-1);
        for (int i = 0; i < n; ++i) 
        {
            if (bit & (1<<i)) 
            { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        sort(S.begin(),S.end());

        for (int hc = 0;hc<h;hc++)
        {
            for (int wc = 0;wc<w;wc++)
            {
                if(find(S.begin(),S.end(),hc) == S.end())
                {
                    if(find(S.begin(),S.end(),wc+h)==S.end())
                    {
                        if(c[hc][wc]==1) sum++;
                    }

                }
            }
        }
        if(sum==k) ans ++;
    }



    cout<<ans<<endl;
}