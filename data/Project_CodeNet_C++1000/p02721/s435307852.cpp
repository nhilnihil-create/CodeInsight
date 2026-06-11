#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}


int main(){
    int N, K, C; cin >> N >> K >> C;
    string S; cin >> S;

    vi ord(N, -1);
    int cnt=0, pos=0;
    while(pos < N){
        if(S[pos] == 'o'){
            cnt++;
            ord[pos]=cnt;
            pos+=C+1;
        }
        else pos++;
    }

    cnt=K, pos=N-1;
    vi ans;
    while(pos >= 0){
        if(S[pos] == 'o'){
            if(ord[pos] == cnt) ans.push_back(pos+1);
            pos-=C+1;
            cnt--;
        }
        else pos--;
    }

    reverse(all(ans));
    for(auto x : ans) cout << x << endl;
    return 0;
}