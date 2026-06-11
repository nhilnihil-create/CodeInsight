#include <bits/stdc++.h>
#define ep emplace_back
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    if (t.substr(0,s.size())==s) {
        cout << "Yes";
    }else cout <<"No";
    return 0;
}
