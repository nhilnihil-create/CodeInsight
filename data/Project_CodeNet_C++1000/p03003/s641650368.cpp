#include <bits/stdc++.h>
using namespace std;

long mod = 1e9+7;
void Main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    vector<int> t(m);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    vector<vector<long>> p(n, vector<long>(m));
    if(s[0] == t[0]) p[0][0] = 1;
    for (int i = 1; i < n; i++){
        p[i][0] = p[i-1][0];
        if(s[i] == t[0]){
            p[i][0] += 1;
            p[i][0] %= mod;
        }
    }  
    for (int i = 1; i < m; i++){
        p[0][i] = p[0][i-1];
        if(s[0] == t[i]){
            p[0][i] += 1;
            p[0][i] %= mod;
        }
    } 
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            p[i][j] = p[i][j-1];
            p[i][j] %= mod;
            p[i][j] += p[i-1][j];
            p[i][j] %= mod;
            p[i][j] -= p[i-1][j-1];
            if(p[i][j] < mod) p[i][j] += mod;
            p[i][j] %= mod;
            if(s[i] == t[j]){
                p[i][j] += p[i-1][j-1]+1;
                p[i][j] %= mod;
            }
        }
    }
    cout << p[n-1][m-1]+1 << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}