#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60; //10e18+10e17ちょっとくらい
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string s, t;
    cin >> s >> t;
    map<string, int> mp;
    int a, b;
    cin >> a >> b;
    mp[s] = a;
    mp[t] = b;
    string u;
    cin >> u;
    mp[u]--;
    cout << mp[s] << " " << mp[t] << endl;

    return 0;
}