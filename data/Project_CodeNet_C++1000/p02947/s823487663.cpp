#include<bits/stdc++.h>
#define ll long long int
#define fi first
#define se second
#define vec vector<lld>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //code :-
    ll n, i, sum = 0;
    cin >> n;
    map<string, ll>m;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    for (auto x : m) {
        //cout<<x.fi<<"-"<<x.se<<endl;
        if (x.se > 1) {
            sum += (x.se * (x.se - 1)) / 2;
        }
    }
    cout << sum << endl;
    return 0;
}

