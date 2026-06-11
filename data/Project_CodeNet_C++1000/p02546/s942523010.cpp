#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define INF 1e9

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
}

int main()
{
    init();
    string s;
    cin>>s;

    if(s[s.size()-1]=='s'){
        s.push_back('e');
        s.push_back('s');
    }else s.push_back('s');
    cout<<s<<endl;
}
