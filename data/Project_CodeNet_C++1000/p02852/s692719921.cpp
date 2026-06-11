#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    
    vector<int> next(N + 1, -1);
    for (int i = N; i >= 0; i--)
    {
        if (S[i] == '0')
            next[i] = i;
        else
            next[i] = next[i + 1];
    }

    vector<int> res;

    int s = N;
    while(s){
        int ns = next[max(0,s-M)];
        if(ns==s){
            cout<<-1<<endl;
            return 0;
        }
        res.push_back(s-ns);
        s = ns;
    }
    reverse(res.begin(), res.end());

    rep(i, res.size())
    {
        cout << res.at(i);
        if (i != res.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
