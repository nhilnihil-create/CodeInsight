#include<bits/stdc++.h>
using namespace std;

int main(){
    int K;
    cin >> K;
    queue<int64_t> lunlun;
    for(int i=1; i<10; i++) lunlun.push(i);

    int64_t t;
    for(int i=0; i<(K-1); i++){
        t = lunlun.front();
        lunlun.pop();
        if(t%10 != 0) lunlun.push(t * 10 + (t % 10 - 1));
        lunlun.push(t * 10 + t % 10);
        if(t%10 != 9) lunlun.push(t * 10 + (t % 10 + 1));
    }

    cout << lunlun.front() << endl;
}