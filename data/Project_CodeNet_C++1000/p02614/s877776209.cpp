#include<bits/stdc++.h>
#define ll long long
using namespace std;
char maps[7][7];
int sum;
int ans;
int a[7];
int b[7];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>maps[i][j];
            if(maps[i][j]=='#')
            {
                sum++;
                a[i]++;
                b[j]++;
            }
        }
    }
    for(int i = 0; i < (1<<n); i++)
    {
        for(int x = 0; x < (1<<m); x++)
        {
            int t=sum;
            for(int j = 0; j < n; j++)
            {

                if(i & (1 << j))
                {
                    t=t-a[j];
                }
            }
            for(int y = 0; y < m; y++)
            {
                if(x & (1 << y))
                {
                    t=t-b[y];
                }
            }
            for(int j = 0; j < n; j++)
            {
                for(int y = 0; y < m; y++)
                {
                    if(i & (1 << j)&&x & (1 << y))
                    {
                        if(maps[j][y]=='#')
                        {
                            t++;
                        }
                    }
                }
            }
            if(t==k)
            {
                ans++;
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}