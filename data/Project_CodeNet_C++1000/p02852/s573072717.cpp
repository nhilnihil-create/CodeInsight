#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    int idx = n;
    vector<int> ans;
    while(1) {
//        cout << idx << endl;
        if ( idx == 0 ) {
            break;
        }
        int dif_num = m;
        while(1) {
            if ( dif_num == 0 ) {
                cout << -1 << endl;
                return 0;
            }
            if ( idx - dif_num < 0 ) {
                --dif_num;
                continue;
            }
            if ( s[idx-dif_num] != '1' ) {
                idx -= dif_num;
                ans.push_back(dif_num);
                break;
            }
            --dif_num;
        }
    }
    reverse(ans.begin(), ans.end());
    for ( int i = 0; i < ans.size(); ++i ) {
        if ( i >= 1 ) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
