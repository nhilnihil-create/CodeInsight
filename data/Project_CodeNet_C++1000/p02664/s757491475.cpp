#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    string T;
    cin >> T;
    rep(i,T.size()) cout << (T[i] == '?' ? 'D' : T[i]);
    cout << endl;
    
    return 0;
}