#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI arccos(-1)
#define rep(i, N) for (int i = 0; i < (N); i++)
#define REP(i, a, N) for (int i = a; i < (N); i++)
#define rrep(i, N, k) for (int i = (N); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

int main() {
    int N;
    cin >> N;
    multiset<int> now;
    for (int i = 0; i < (1<<N); i++) {
        int S;
        cin >> S;
        now.insert(S);
    }
    bool check = true;
    vector<int> explore;
    explore.push_back(*now.rbegin());
    now.erase(next(now.end(), -1));
    while (!now.empty()) {
        vector<int> temp;
        for (auto ancestor : explore) {
            auto itr = now.lower_bound(ancestor);
            if (itr == now.begin()) {
                check = false;
                break;
            }
            itr--;
            temp.push_back(*itr);
            now.erase(itr);
        }
        if (!check) break;
        for (auto next : temp) explore.push_back(next);
    }
    cout << (check ? "Yes" : "No") << endl;
}