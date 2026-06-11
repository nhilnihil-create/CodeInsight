#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    long long n, m;

    cin >> n >> m;

    priority_queue<long long> q;

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        q.push(a);
    }

    for(long long i = 0; i < m; i++){
        long long maxv = q.top();
        q.pop();
        q.push(maxv/2);
    }

    long long sum = 0;

    while(!q.empty()){
        long long top = q.top();
        q.pop();
        sum += top;
    }

    cout << sum << endl;
    
    return 0;
}