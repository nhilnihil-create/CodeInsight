#include<bits/stdc++.h>
using namespace std;

static const int INF=1e9;
static const int MOD=1000000007;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int N; cin >> N;
    ll a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    sort(a,a+N);
    vector<pair<ll,ll>> ans;
    ll tmp=a[0];
    for(int i=1;i<N-1;i++){
        if(a[i]>=0){
            ans.push_back({tmp,a[i]});
            tmp-=a[i];
        }
    }
    ans.push_back({a[N-1],tmp});
    tmp=a[N-1]-tmp;
    for(int i=1;i<N-1;i++){
        if(a[i]<0){
            ans.push_back({tmp,a[i]});
            tmp-=a[i];
        }
    }
    cout << tmp << endl;
    for(int i=0;i<N-1;i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}
