#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct Edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const long double EPS = 10e-10;

int main(){
    int N,M,tmp;
    while(true){
        cin >> N >> M;
        if(!N && !M) break;
        vector<int> h(N+1, 0), w(M+1, 0);
        map<int, int> maph, mapw;
        reppp(i, 1, N+1){
            cin >> tmp;
            h[i] = tmp + h[i-1];
            repp(j, i){
                maph[h[i]-h[j]]++;
            }
        }
        reppp(i, 1, M+1){
            cin >> tmp;
            w[i] = tmp + w[i-1];
            repp(j, i){
                mapw[w[i]-w[j]]++;
            }
        }

        int ans = 0;
        for(auto itr=maph.begin();itr!=maph.end();++itr){
            int h = itr->first;
            ans += (itr->second) * mapw[h];
        }
        cout << ans << endl;
    }
}

