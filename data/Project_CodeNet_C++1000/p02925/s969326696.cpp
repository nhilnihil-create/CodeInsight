#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;


int main(){
    int N; cin >> N;
    vector<queue<int>> Q(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-1; j++) {
            int x; cin >> x; x--;
            Q[i].push(x);
        }
    }

    ll ans = 0;
    vector<int> B1(N);

    queue<int> Q2;
    for(int i = 0; i < N-1; i++){
        int x = Q[i].front();
        if(Q[i].empty() || B1[i] == 1) continue;
        int y = Q[x].front();
        if(Q[x].empty() || B1[x] == 1) continue;
        if(i == y){
            Q[i].pop(); Q[x].pop();
            Q2.push(i);Q2.push(x);
            B1[i] = 1; B1[x] = 1;
            //cout << ans << "  " << i << " " << x << endl;
        }
    }
    if(Q2.empty()){ cout << -1 << endl; return 0;}
    ans++;

    while(1){
        vector<int> B(N);
        bool flag = true;
        queue<int> Q3 = Q2, q;
        swap(Q2, q);
        while(!Q3.empty()){
            int i = Q3.front(); Q3.pop();
            if(Q[i].empty() || B[i] == 1) continue;
            int x = Q[i].front();

            if(Q[x].empty() || B[x] == 1) continue;
            int y = Q[x].front();
            if(i == y){
                B[i] = 1; B[x]=1;
                Q[i].pop(); Q[x].pop();
                Q2.push(i);Q2.push(x);
                //cout << ans << " " << i << " " << x << endl;
                flag = false;
            }
        }
        if(flag) break;
        ans++;
    }

    for(int i = 0; i < N; i++) {
        if(!Q[i].empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}