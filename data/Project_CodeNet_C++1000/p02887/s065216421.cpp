#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30

vector<pair<char, int>> runlength(string s) {
    int n = s.size();
    vector<pair<char, int> > res;
    char pre = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(pre != s[i]){
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.push_back({pre, cnt});
    return res;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    V<P<char, int> > v = runlength(s);

    cout << v.size() << endl;

    return 0;
}
