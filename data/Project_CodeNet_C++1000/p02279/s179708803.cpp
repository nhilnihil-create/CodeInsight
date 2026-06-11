#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int MAX = 100100;
vector<int> G[MAX];
int id[MAX],pa[MAX],dp[MAX],used[MAX];

void dfs(int v,int d){
    dp[v] = d;                       //深さを更新
    for(int i=0;i<(int)G[v].size();i++){
        dfs(G[v][i],d+1);
        pa[G[v][i]] = v;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;                           //n : the number of node
    cin >> n;

    rep(i,n){
        int k;                       //k : the number of child which the node has  
        cin >> id[i] >> k;
        G[id[i]].resize(k);          //G : graph
        rep(j,k){
            cin >> G[ id[i] ][j];    //G[from][number] = to  G[親][番号] = 子
            used[ G[id[i]][j] ] = 1; //used[parent] 子がリストアップされていく
        }
    }
    memset(pa,-1,sizeof(pa));        //すべてのnodeを根にする
    rep(i,n){
        if(!used[i]) dfs(i,0);       //根なら（子じゃなかったら）dfs
    }

//---出力---//
    rep(i,n){
        cout << "node "       << i;
        cout << ": parent = " << pa[i];
        cout << ", depth = "  << dp[i];
        cout << ", ";
        if(pa[i]<0) cout << "root";
        else if(!G[i].size()) cout << "leaf";  //子を持ってなかったら葉
        else cout << "internal node";
        cout << ", [";
        rep(j,G[i].size()){
            if(j) cout << ", ";
            cout << G[i][j];
        }
        cout << "]" << endl;
    }

    return 0;
}

