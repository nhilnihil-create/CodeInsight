#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector< vector<int> > edg;
vector< int > deg, day;
int d2i(int x, int y){
    if(x > y) return d2i(y, x);
    return x + (y-1)*y/2;
}
int main(void){
    cin >> n;
    m = n*(n-1)/2;
    edg.assign(m, vector<int>());
    deg.assign(m, 0);
    day.assign(m, 0);
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        b = d2i(i, --b);
        for(int j=1;j<n-1;j++){
            int a;
            cin >> a;
            a = d2i(i, --a);
            edg[b].push_back(a);
            deg[a]++;
            b = a;
        }
    }
    int ans = 0, cnt = 0;
    queue<int> q;
    for(int i=0;i<m;i++){
        if(deg[i] == 0){
            q.push(i);
            day[i] = 1;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(ans < day[v]) ans = day[v];
        cnt++;
        for(int x : edg[v]){
            if(--deg[x] == 0){
                q.push(x);
                day[x] = day[v] + 1;
            }
        }
    }
    if(cnt < m) ans = -1;
    cout << ans << endl;
}
