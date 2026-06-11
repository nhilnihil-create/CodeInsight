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
    int N; cin >> N;
    vii ids(N);
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        ids[a].push_back(i);
        ids[b].push_back(i);
    }
    vi color(N-1, -1);
    int dm=0;
    for(int i=0; i<N; i++){
        dm=max(dm, (int)ids[i].size());
    }
    for(int i=0; i<N; i++){
        vector<bool> ng(dm+1, 0);
        for(auto &e : ids[i]){
            if(color[e] != -1){
                ng[color[e]]=1;
            }
        }
        int c=1;
        for(auto &e : ids[i]){
            if(color[e] != -1) continue;
            if(ng[c]){
                while(ng[c]){
                    c++;
                }
                color[e]=c;
            }
            else{
                color[e]=c;
            }
            c++;
        }
    }
    cout << dm << endl;
    for(int i=0; i<N-1; i++) cout << color[i] << endl;
    return 0;
}