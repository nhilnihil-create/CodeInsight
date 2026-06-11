#include <fstream>
#include <deque>
#include <vector>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, M;
string str;
deque<int> unvis;
deque<int> unpro;
int mov [100001] = {0};

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> str;
    F0R(i,str.size()) if (str[i] == '0') unvis.PB(i);
    unvis.pop_front();
    unpro.PB(0);
    while (!unpro.empty()) {
        int cur = unpro.front(); unpro.pop_front();
        // cout << "cur: " << cur << '\n';
        while (!unvis.empty() && unvis.front() <= cur+M) {
            if (unvis.front() >= cur+1) {
                // cout << "   add: " << unvis.front() << '\n';
                mov[unvis.front()] = unvis.front()-cur;
                unpro.PB(unvis.front());
            }
            unvis.pop_front();
        }
    }
    if (mov[N] == 0) cout << "-1\n";
    else {
        vector<int> ans;
        while (N != 0) {
            ans.PB(mov[N]);
            N -= mov[N];
        }
        RF0(i,ans.size()) {
            cout << ans[i];
            if (i != 0) cout << ' ';
        }
        cout << '\n';
    }
}