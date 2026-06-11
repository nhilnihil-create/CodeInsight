#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> nx(n);
    for(int i = 0; i < n; i++){
        cin >> nx[i];
        nx[i]--;
    }
    vector<int> visited(n);
    int u = 0, cnt = 0;
    int v = -1, loop = 0;
    while(!visited[u] || u != 0){
        if(visited[u] == 1 && u != 0){
            v = u;
            while(visited[v] < 2){
                visited[v]++;
                v = nx[v];
                loop++;
            }
            break;
        }
        visited[u]++;
        u = nx[u];
        cnt++;
    }
    if(v == -1){
        v = 0;
        loop = cnt;
    }
    //cout << cnt << " " << loop << endl;
    if(k < cnt - loop){
        u = 0;
        for(int i = 0; i < k % cnt; i++){
            u = nx[u];
        }
        cout << u+1 << endl;
    } else {
        int t = (k - cnt + loop) % loop;
        for(int i = 0; i < t; i++){
            v = nx[v];
        }
        cout << v+1 << endl;
    }
    return 0;
}