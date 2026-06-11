#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N, M;
    cin >> N >> M;
    vector<P> C(N);
    for(int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        C[i] = P(a, b);
    }
    sort(C.begin(), C.end());
    int j = 0;
    priority_queue<long long> q;
    long long ans = 0;
    for(int i = 1; i <= M; i++){
        while(C[j].first == i && j < N){
            q.push(C[j].second);
            j++;
        }
        if(!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
}