#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    int a, b, m;
    int fridge_min = 1000000, microwave_min = 1000000;
    cin >> a >> b >> m;
    vector<int> fridge(a), microwave(b), x(m), y(m), c(m);
    for(int i = 0; i < a; i++){
        cin >> fridge[i];
        fridge_min = min(fridge_min, fridge[i]);
    }
    for(int i = 0; i < b; i++){
        cin >> microwave[i];
        microwave_min = min(microwave_min, microwave[i]);
    }
    int ans = 1000000007;
    for(int i = 0; i < m; i++){ //割引券使った時の最小値
        int x, y, c;
        cin >> x >> y >> c;
        int use_ticket = fridge[x-1]+microwave[y-1]-c;
        ans = min(ans, use_ticket);
    }
    ans = min(ans, fridge_min+microwave_min);
    cout << ans << endl;
    return 0;
}
