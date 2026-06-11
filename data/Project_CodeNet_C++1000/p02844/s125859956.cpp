#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll n;
    string s, pin, sub_s;
    int ans = 0, pos;
    bool ok;
    cin >> n >> s;
    REP(i,1000){
        ostringstream sout;
        sout << std::setfill('0') << std::setw(3) << i;
        pin = sout.str();
        sub_s = s;
        ok = true;
        REP(j,3)
        {
            pos = sub_s.find_first_of(pin[j]);
            if(pos != string::npos){
                sub_s = sub_s.substr(pos+1);
            }
            else{
                ok = false;
                break;
            }
        }
        if(ok) ans += 1;
    }
    printf("%d", ans);

    return 0;
}