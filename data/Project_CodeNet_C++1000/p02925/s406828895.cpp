#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int MX = 1005;
vector<vector<int>> ID(MX,vector<int>(MX,0));
vector<vector<int>> game(MX*(MX-1)/2,vector<int>());
vector<int> in(MX*(MX-1)/2,0);

int id(int i,int j){
    if(i > j) swap(i,j);
    return ID[i][j];
}

int main(){
    int n;
    cin >> n;
    int v = 1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ID[i][j] = v++;
        }
    }
    --v;

    vector<vector<int>> a(n,vector<int>(n-1,0));
    rep(i,n)rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }

    rep(i,n)rep(j,n-2){
        game[id(i,a[i][j])].push_back(id(i,a[i][j+1]));
        in[id(i,a[i][j+1])] ++;
    }

    for(int i=1;i<=v;i++){
        if(in[i] == 0){
            game[0].push_back(i);
            in[i] ++;
        }
    }

    vector<int> day(v+1,0);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next:game[now]){
            in[next] --;
            if(in[next] == 0){
                day[next] = day[now] + 1;
                q.push(next);
            }
        }
    }
    bool ok = true;
    int ans = 0;
    rep(i,v){
        ans = max(ans,day[i+1]); 
        if(day[i+1] == 0){
            ok = false;
            break;
        }
    }
    
    if(ok) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}

