#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N, M;
    cin>>N>>M;
    vector<pint> W(N);
    REP(i, 0, N){
        int a, b;
        cin >> a >> b;
        W[i] = {a, b};
    }
    sort(W.begin(), W.end());
    priority_queue<int> que;
    int count = 0, ans = 0;
    REP(i, 1, M+1){
        while(W[count].first == i && count < N){
            que.push(W[count].second);
            count++;
        }
        
        int q;
        if(!que.empty()){
            q = que.top(); 
            que.pop();
        }else{
            q = 0;
        }
        ans += q;
    }
    cout << ans << endl;
}