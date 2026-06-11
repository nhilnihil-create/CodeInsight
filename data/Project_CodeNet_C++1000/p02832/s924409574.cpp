#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];

int main() {
    int n;
    cin >> n;
    int ans = -1;
    int index = 1;
    rep(i, 0, n){
        int num;
        cin >> num;
        if(num == index){
            ans++;
            index++;
        }
    }
    if(ans < 0)cout << ans << endl;
    else {
        n-=ans+1;
        cout << n << endl;
    }
    return 0;
}
