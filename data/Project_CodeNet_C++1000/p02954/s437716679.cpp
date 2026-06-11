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
    string S; cin >> S;
    int N=S.size();
    
    int pos=0, cnt=0;
    bool flag=false;
    vi ans(N, 0);
    for(int i=0; i<N; i++){
        if(S[i] == 'R'){
            cnt++;
            flag=false;
        }
        else if(S[i] == 'L' && !flag){
            pos=i;
            ans[pos-1]+=(cnt+1)/2;
            ans[pos]+=(cnt)/2+1;
            cnt=0;
            flag=true;
        }
        else if(S[i] == 'L' && flag){
            if((i-pos)%2 == 1) ans[pos-1]++;
            else ans[pos]++;
        }
    }
    for(int i=0; i<N; i++){
        cout << ans[i] << (i==N-1?"\n":" ");
    }
    return 0;
}