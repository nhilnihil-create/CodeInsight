#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int>cnt[26];
signed main() {
    string S,T;
    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) {
        cnt[S[i]-'a'].push_back(i);
    }
    for(int i = 0; i < T.size(); i++) {
        if(cnt[T[i]-'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    int now = -1;
    int res = 0;
    for(int i = 0; i < T.size(); i++) {
        int l = -1,r = cnt[T[i]-'a'].size();
        while(l+1 < r) {
            int mid = (l+r)/2;
            if(cnt[T[i]-'a'][mid] > now) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if(r == cnt[T[i]-'a'].size()) {
            now = cnt[T[i]-'a'][0];
            res++;
        }
        else {
            now = cnt[T[i]-'a'][r];
        }
    }
    cout << now+res*S.size()+1 << endl;
}
