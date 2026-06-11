#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

int main()
{
    int N, M, t, x, y;   cin >> N >> M;
    long long ans;
    vector<int> a(N), c(31,0);
    priority_queue<int> que;
    for(int i=0; i<N; i++){
        cin >> x;
        que.push(x);
    }
    ans = 0;
    t = 0;
    while(!que.empty()){
        x = que.top();
        que.pop();
        que.push(x/2);
        t++;
        if(t >= M || x == 0)   break;
    }
    for(int i=0; i<N; i++){
        x = que.top();
        ans += x;
        que.pop();
    }
    cout << ans;
}