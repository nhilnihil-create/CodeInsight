#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1e9+7
#define INF 1 << 30
#define MAX (1 << 20)
#define NINF (-(1 << 30))
#define Point pair<int, int>
#define triplet pair<pair<int, int>, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    if(s[s.size() - 1] == 's') {
        s.push_back('e');
    }
    s.push_back('s');

    cout << s << endl;
    return 0;
}