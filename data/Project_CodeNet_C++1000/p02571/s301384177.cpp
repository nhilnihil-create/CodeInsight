#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 100000000
using pi = pair<int, int>;
int main()
{
    string  s1, s2;
    cin >> s1 >> s2;
    int mx = 0, n = s1.size(), m = s2.size();
    for(int i = 0; i <= n - m; i++)
    {
        int k = 0;
        for(int j = 0; j < m ; j++)
        {
            if(s1[j+i] == s2[j])
                k++;
        }
        mx = max(k, mx);
    }
    cout << s2.size() - mx << endl;

}
