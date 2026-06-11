#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, M;
string S;
vector<int> ans;

signed main(){
    cin >> N >> M >> S;
    int cnt = 0;
    rep(i, N+1){
        if(S[i] == '1') cnt++;
        else cnt = 0;
        if(cnt >= M){
            cout << -1 << endl;
            return 0;
        }
    }
    int i = N;
    while(i > 0){
        for(int j=max(0, i-M); j<i; j++){
            if(S[j] == '0'){
                ans.pb(i-j);
                i = j;
                break;
            }
        }
    }
    reverse(all(ans));
    rep(i, ans.size()) cout << ans[i] << endl;
}