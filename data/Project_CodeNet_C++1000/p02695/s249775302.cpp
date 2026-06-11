#include<bits/stdc++.h>
using namespace std;
int ans;
vector<vector<int>> q1(51);
int q;
vector<int> v;
void score(int s, int n, int prev, int m, int *ans)
{
    if(s == n)
    {   
       int tmp = 0;
    //    for(int i=0; i<n; i++)
    //    {
    //        cout<<v[i]<<'\n';
    //    }
       for(int k=0; k<q; k++)
       {
          
            if( ( v[q1[k][1] - 1] - v[q1[k][0] - 1] ) == q1[k][2] )
            {
                tmp += q1[k][3];
                // cout<<tmp<<'\n';
            }
            // cout<<v[q1[k][1]-1]<<" "<<q1[k][1]<<" "<<k<<'\n';
       }
    //    cout<<ans<<'\n';
       *ans = max(*ans, tmp);
       return;
    }
    for(int i=prev; i<=m; i++)
    {
        v.push_back(i);
        score(s + 1, n, i, m, ans);
        v.pop_back();
    }
}
int main()
{
    int n,m;
    cin>>n>>m>>q;
    int ans = 0;
    for(int i=0; i<q; i++)
    {
        for(int j=0; j<4; j++)
        {
            int x;
            cin>>x;
            q1[i].push_back(x);
            // cout<<q1[i][j]<<" ";
        }
        // cout<<'\n';
    }
    ans = 0;
    score(0, n, 1, m, &ans);
    cout<<ans<<'\n';
}
