#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, M;
int dp[1000010];
string S;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> S;
    vector<int> vs;
    for(int i = 0; i < S.length(); ++i){
        if(S[i] == '0') vs.emplace_back(i);
    }
    vector<int> ans;
    int last = N;
    bool flag = true;
    while(flag){
        auto it = lower_bound(vs.begin(), vs.end(), last - M);
        if(last == *it){
            flag = false;
        }else{
            ans.push_back(last - *it);
            last = *it;
            if(*it == 0) break;
        }
    }
    if(!flag){
        cout << -1 << endl;
    }else{
        for(int i = ans.size() - 1; i >= 0; --i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}