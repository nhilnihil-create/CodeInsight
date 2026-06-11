#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ll,ll> pll;

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    cout << (s == "ABC" ? "ARC" : "ABC") << '\n';
    return 0;
}