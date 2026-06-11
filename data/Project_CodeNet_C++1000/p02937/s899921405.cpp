#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int n = (int)s.length();
    vector<vector<int>> dic(26);
    for(int i = 0; i < n; ++i)
    {
        char c = s[i];
        dic[c - 'a'].push_back(i);
    }
    for(int i = 0; i < n; ++i)
    {
        char c = s[i];
        dic[c - 'a'].push_back(i+n);
    }

    long long int ans = 0;
    int p = 0;
    for(int i = 0; i < (int)t.length(); ++i)
    {
        char c = t[i];
        if((int)dic[c-'a'].size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(dic[c-'a'].begin(),dic[c-'a'].end(),p)+1;
        if(p >= n)
        {
            p -= n;
            ans += n;
        }
    }
    ans += p;
    cout << ans << endl;
}