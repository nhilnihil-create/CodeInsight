#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,m;string s;
    cin >> n >> m >> s;
    int pos = n;
    bool ok = true;
    stack<int> ans;
    while(pos!=0){
        int k=0;
        for(int j=1;j<=m && pos-j>=0;++j){
            if(s[pos-j]=='0') k = j;
        }
        if(k==0){
            ok = false;
            break;
        }
        ans.push(k);
        pos -= k;
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    while(ans.size()){
        cout << ans.top() << endl;
        ans.pop();
    }
}