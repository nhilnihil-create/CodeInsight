//ssenseeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;
#define MX 1000000000
#define endl '\n'
#define startt ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr first
#define sc second
#define MOD 1000000007

int main()
{
    int a[10][10] = {0};
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        int first = s[0]-'0';
        int second = s[s.size()-1] - '0';
        a[first][second]++;
    }
    
    int ans = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            ans+=a[i][j]*a[j][i];
        }
    }
    cout << ans << endl;
}
