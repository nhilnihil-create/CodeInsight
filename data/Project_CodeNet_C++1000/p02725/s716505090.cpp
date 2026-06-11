#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    int K, N;
    cin >> K >> N;

    priority_queue<int> Aque;
    int val;
    for(int i=0; i<N; i++){
        cin >> val;
        Aque.push(val);
    }
    int max_val = Aque.top();
    
    priority_queue<int> DistanceQue;
    while (Aque.size() > 1){
        int val1 = Aque.top();Aque.pop();
        int val2 = Aque.top();
        DistanceQue.push(val1 - val2);
    }

    int minVal = Aque.top();
    DistanceQue.push(K-max_val+minVal);
    DistanceQue.pop();

    int ans = 0;
    while(!DistanceQue.empty()){
        int val1 = DistanceQue.top();DistanceQue.pop();
        ans += val1;
    }

    cout << ans << endl;

    return 0;

}