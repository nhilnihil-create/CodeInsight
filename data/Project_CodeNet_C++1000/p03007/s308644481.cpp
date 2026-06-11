#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A_m,A_p;
    rep(i,N){
        int A;
        cin >> A;
        if(A>=0) A_p.push_back(A);
        else A_m.push_back(A);
    }
    sort(A_m.begin(),A_m.end());
    sort(A_p.rbegin(),A_p.rend());
    if(A_m.size()==0){
        A_m.push_back(A_p.back());
        A_p.pop_back();
    }
    if(A_p.size()==0){
        A_p.push_back(A_m.back());
        A_m.pop_back();
    }
    vector<pair<ll,ll>> op;
    ll ans = A_m[0];
    rep(i,A_p.size()-1){
        op.push_back(make_pair(ans,A_p[i]));
        ans -= A_p[i];
    }
    op.push_back(make_pair(A_p.back(),ans));
    ans = A_p.back() - ans;
    for(int i=1;i<A_m.size();i++){
        op.push_back(make_pair(ans,A_m[i]));
        ans -= A_m[i];
    }
    cout << ans << endl;
    rep(i,N-1) cout << op[i].first << " " << op[i].second << endl;
    return 0;
}