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
    int n; cin >> n;
    vector<queue<int>> com(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            int a; cin >> a;
            a--;
            com[i].push(a);
        }
    }

    int ans=0;
    while(1){
        ans++;
        vi fight;
        for(int i=0; i<n; i++){
            if(com[i].empty()) continue;
            int player=com[i].front();
            if(com[player].front() == i){
                fight.push_back(i);
            }
        }
        for(int i=0; i<(int)fight.size(); i++){
            com[fight[i]].pop();
        }
        if(fight.empty()){
            ans=-1;
            break;
        } 
        bool fin=true;
        for(int i=0; i<n; i++){
            if(!com[i].empty()) fin=false;
        }
        if(fin) break;
    }

    cout << ans << endl;
    /*
    int n; cin >> n;
    vi x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    */
    
    return 0;
}