#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,now = 0;
    long long int ans = 0;
    cin >> N >> M;
    vector<pair<int,int>> AB(N);
    for(int i=0;i<N;i++){
        pair<int,int> P;
        cin >> P.first >> P.second;
        AB[i] = P;
    }

    sort(AB.begin(),AB.end());
    priority_queue<int> Q;

    for(int i=1;i<=M;i++){
        while(now!=N && AB[now].first<=i){
            Q.push(AB[now].second);
            now++;
        }

        if(!Q.empty()){
            ans += Q.top();
            Q.pop();
        }
    }

    cout << ans << endl;
}