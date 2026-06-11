#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}



int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans=0, cnt1=0, cnt2=0;
    cnt1+=(s[0]=='L')+(s[n-1]=='R');
    for(int i=0; i+1<n; i++){
        if(s[i] == 'R' && s[i+1] == 'L') cnt2++;
    }
    if(cnt1 == 0){
        if(k < cnt2) ans=n-(cnt2-k)*2;
        else ans=n-1;
    }
    else{
        if(k <= cnt2) ans=n-(cnt2-k)*2-cnt1;
        else ans=n-1;
    }
    cout << ans << endl;
    return 0;
}