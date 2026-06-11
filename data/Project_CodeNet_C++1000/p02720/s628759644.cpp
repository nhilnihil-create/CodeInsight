#include <iostream>
#include <queue>

using namespace std;

int main(){
    int K; cin >> K;
    queue<long long> qu;
    for(int i=1;i<10;i++) qu.push(i);
    while(--K){
        auto t = qu.front(); qu.pop();
        int b = t%10;
        for(int i=max(0, b-1);i<=min(9, b+1);i++){
            qu.push(10 * t + i);
        }
    }
    cout << qu.front() << endl;
}