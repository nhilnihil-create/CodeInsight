#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    map<string,int> mp;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
        mp[S[i]]++;
    }
    int cnt = 0;
    rep(i,N){
        cnt = max(cnt,mp[S[i]]);
    }
    vector<string> ans;
    rep(i,N){
        if(mp[S[i]]==cnt){
            ans.push_back(S[i]);
            mp[S[i]]=0;
        }
    }
    sort(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}