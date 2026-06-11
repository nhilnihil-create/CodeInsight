#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;
const double PI = 3.141592653589793238460;
const int INF = 1e9+5;
int ans = INF;
int x;
void recur(int cost[], vector<int> books[], vector<int>& knowledge, int start, int n, int m, int& res){

    bool flag=true;
    for(int i = 0; i<m; i++){
        if(knowledge[i]<x){
            flag=false;
            break;
        }
    }

    if(flag){
        ans = min(ans, res);
        return;
    }

    for(int i = start; i < n; i++){

        res+=cost[i];
        for(int j=0; j<m; j++){
            knowledge[j]+=books[i][j];
        }
        recur(cost, books, knowledge, i+1, n, m, res);
        res-=cost[i];
        for(int j=0; j<m; j++){
            knowledge[j]-=books[i][j];
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m >> x;
    int cost[n];
    vector<int> books[n];    

    for(int i=0; i<n; i++){
        cin >> cost[i];
        for(int j=0; j<m; j++){
            int t;
            cin >> t;
            books[i].push_back(t);
        }
    }

    vector<int> knowledge(m,0);
    int res = 0;
    recur(cost, books, knowledge, 0, n, m, res);

    ans==INF?cout<<(-1):cout<<ans;

    return 0;
}
