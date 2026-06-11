#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n, tot = 0;
        cin >> n;
        map<string, int> prefix;
        for (int i = 0; i < n; i++)
        {
                int val;
                string s;
                cin >> s >> val;
                tot += val;
                prefix[s] = tot;
        }
        string s;
        cin >> s;
        cout << tot - prefix[s] << "\n";
}
