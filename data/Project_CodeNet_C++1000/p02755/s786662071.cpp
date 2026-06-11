#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout << (x ? "Yes" : "No") << endl;
#define out(s) cout << s << endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(), s.end()
void vout(vi v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;
}
int main()
{
    set<int> a, b;
    lli A, B;
    cin >> A >> B;
    rep(i, 100000)
    {
        if (((lli)(i * 0.08)) == A)
        {
            a.insert(i);
        }
        if (((lli)(i * 0.1)) == B)
        {
            b.insert(i);
        }
    }
    lli ans = -1;
    for (lli v : a)
    {
        if (b.count(v))
        {
            ans = v;
            break;
        }
    }
    out(ans);
}