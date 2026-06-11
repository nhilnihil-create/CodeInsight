/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

const int mod = 1e9+7;

int n;
int k;
long long ans = 1;
vector < int > adj[N];

void dfs(int u , int p){
    int st;
    if(p == 0){
        st = k - 1;
    } else {
        st = k - 2;
    }
    if(p != 0 && adj[u].size() - 1 > k)
        ans = 0;
    //cout << u << endl;
    //system("PAUSE");
    for(auto v : adj[u]){
        if(v == p)
            continue;
        ans *= st;
        st--;
        ans %= mod;
        dfs(v , u);
    }
}


int main(){
    scanf("%d%d" , &n , &k);
    for(int i = 1; i < n; i++){
        int u , v;
        scanf("%d%d" , &u , &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = k;
    dfs(1 , 0);
    printf("%d\n" , (int)ans);
}