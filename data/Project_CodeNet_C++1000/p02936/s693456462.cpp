#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

const int N = 2e5;
vector <int> adj[N];
int n , q;
ll lazy[N];

void dfs (int u = 0 , int p = -1){
    for (int v : adj[u]){
        if (v ^ p){
            lazy[v] += lazy[u];
            dfs(v,u);
        }
    }
}

void Suhaib_Sawalha (){

    cin >> n >> q;
    for (int i = 1 , u , v ; i < n ; ++i){
        cin >> u >> v;
        --u , --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0 , u , c; i < q ; ++i){
        cin >> u >> c;
        lazy[u-1] += c;
    }

    dfs();
    for (int i = 0 ; i < n ; ++i)
        cout << lazy[i] << ' ';

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}