#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char arr[10][10];
int rows[10] , cols[10] ;
int n , m , k ;
int dp[10][10][40];
string s;
vector<string>strs;
int z;
void rec(string s )
{
    if(s.size()==z)
    {
        strs.push_back(s);
        return;
    }
    rec(s+'1');
    rec(s+'0');
}
int main()
{

    cin >> n >> m >> k ;
    z=n+m;
    rec("");
    int cntr=0;
    for(int i = 1 ; i <=n ;i++)
    {
        for(int j = 1 ; j <=m ;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='#')
            {
                rows[i]++;
                cols[j]++;
                cntr++;
            }
        }
    }
    int need =cntr-k;
    int ns=0;
    for(int i = 0 ; i < strs.size() ;i++)
    {
        int f=0;
        for(int j = 1; j<=n;j++)
        {
            for(int k=1; k<=m;k++)
            {
                if(strs[i][j-1]=='0'&&strs[i][n+k-1]=='0')
                {
                    if(arr[j][k]=='#')
                        f++;
                }
            }
        }
        if(f==k)
            ns++;
    }
    cout << ns;
    return 0;
}
