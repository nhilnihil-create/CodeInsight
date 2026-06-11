#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,D,A;
    cin >> N >> D >> A;
    vector<pair<int,int>> Mns(N);
    rep(i,N){
        int x,h;
        cin >> x >> h;
        Mns[i] = make_pair(x,h);
    }
    sort(Mns.begin(),Mns.end());
    // 左から順に区間の左端に重なるように選ぶ
    ll diff=0;
    deque<pair<ll,ll>> dq;
    ll ans =0;
    for(int i=0;i<N;i++){
        int now;
        now = Mns[i].first;
        while(dq.size()!=0){
            if(dq.front().first<=now){
                diff-=dq.front().second;
                dq.pop_front();
            }else{
                break;
            }
        }
        ll d = Mns[i].second-diff;
        // cout << "i:" << i << " d:" << d << endl;
        if(d>0){
            ll tmp = (ll)ceil(d*1.0/(A*1.0));
            ans += tmp;
            diff += A*tmp;
            dq.push_back(make_pair(min(now+2*D+1,1000000005),A*tmp));
        }
    }
    cout << ans << endl;
    return 0;
}