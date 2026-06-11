#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    P tasks[N];
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        tasks[i] = P(a, b);
    }

    sort(tasks, tasks+N);

    priority_queue<int> q;

    int id = 0;
    ll ans = 0;
    for(int i=0; i<=M; i++){
        while(id < N && tasks[id].first <= i){
            q.push(tasks[id].second);
            id++;
        }
        if(!q.empty()){
            ans = ans + q.top();
            q.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
