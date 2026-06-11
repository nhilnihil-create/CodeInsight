#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int l = 0,r = N;
    while (l+1 < r) {
        int mid = (l+r)/2;
        map<string,int>Mp;
        bool ok = false;
        for(int i = 0; i < N-mid+1; i++) {
            if(!Mp.count(S.substr(i,mid))) {
                Mp[S.substr(i,mid)] = i;
            }
            else {
                if(Mp[S.substr(i,mid)]+mid <= i) {
                    ok = true;
                }
            }
        }
        if(ok) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
}
