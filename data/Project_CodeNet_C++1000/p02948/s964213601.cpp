#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int N, M, A, B, i, day, res = 0;
vector<vector<int>> work(100010, vector<int>());
priority_queue<int> profit_q;

int main(){
    cin >> N >> M;
    for(i = 0; i < N; i++){
        cin >> A >> B;
        work[A].pb(B);
    }

    for(day = 1; day <= M; day++){
        for(i = 0; i < work[day].size(); i++) profit_q.push(work[day][i]);
        if(profit_q.empty()) continue;
        res += profit_q.top(); profit_q.pop();
    }

    cout << res << endl;
    return 0;
}


