#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <deque>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long gcd(long long a, long long b){if(b==0)return a;return gcd(b,a%b);}

int charN(char c) {
    return static_cast<int>(c) - static_cast<int>('a');
}
int main() {
    int N; cin >> N;
    vector<pair<ll,ll>> xy;
    repp(i, 0, N) {
        ll x, y; cin >> x >> y;
        xy.emplace_back(x, y);
    }
    sort(xy.begin(), xy.end());
    
    map<pair<ll,ll>, int> counter;
    int count = 0;
    repp(i, 0, N) {
        repp(j, i + 1, N) {
            ++counter[make_pair(xy[j].first - xy[i].first, xy[j].second - xy[i].second)];
            count = max(count, counter[make_pair(xy[j].first - xy[i].first, xy[j].second - xy[i].second)]);
        }
    }
    cout << (N - count) << endl;
}

