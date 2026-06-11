#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    priority_queue<int> que;
    int val;
    for(int i=0; i<N; i++){
        cin >> val;
        que.push(val);
    }

    int large_val;
    int small_val;
    while(que.size() > N/2){
        large_val = que.top(); que.pop();
    }
    small_val = que.top();

    cout << large_val - small_val << endl;
}