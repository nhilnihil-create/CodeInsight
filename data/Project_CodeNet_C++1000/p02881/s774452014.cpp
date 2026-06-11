#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> Q;
    for(long long i = 1; i <= sqrt(N); ++i){
        if(N % i == 0) Q.push(i + N/i);
    }
    cout << Q.top() - 2 << endl;
    return 0;
}