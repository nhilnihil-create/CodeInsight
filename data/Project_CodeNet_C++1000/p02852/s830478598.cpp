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
const ll MOD=1e9+7;

int main(){
    int N, M; cin >> N >> M;
    string S; cin >> S;
    int cur=N;
    vi res;
    while(cur > 0){
        bool ok=false;
        for(int i=M; i>=1; i--){
            if(cur-i < 0){
                i=cur+1;
                continue;
            }
            int next=cur-i;
            if(S[next] != '1'){
                ok=true;
                res.push_back(i);
                cur=next;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(all(res));
    for(int i=0; i<(int)res.size(); i++){
        if(i != 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}