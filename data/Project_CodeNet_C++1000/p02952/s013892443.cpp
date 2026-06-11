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
    int N; cin >> N;
    int tmp=N;
    int cnt=0;
    while(tmp > 0){
        cnt++;
        tmp/=10;
    }
    int ans=0;
    for(int i=1; i<=cnt; i++){
        if(i%2 == 1){
            if(i == cnt) ans+=N-pow(10, i-1)+1;
            else ans+=pow(10, i)-pow(10, i-1);
        }
    }
    cout << ans << endl;
    return 0;
}