#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<(n); i++)
#define REPS(i, n) for(int i=0; i<=(n); i++)
#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define FORS(i, a, b) for(int i=a; i<=(b); i++)
// for container x
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    string s;
    cin >> s;

    if (s[2]!=s[3]) {
        cout << "No";
        return 0;
    }
    if (s[4]!=s[5]) {
        cout << "No";
        return 0;
    }
    cout << "Yes";

    return 0;
}