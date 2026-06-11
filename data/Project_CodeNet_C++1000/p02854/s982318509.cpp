#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N,0);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    long long sum = 0;
    for(int i=0; i<N; i++){
        sum += A[i];
    }
    typedef pair<long long, long long> lengths;
    priority_queue<lengths, vector<lengths>, greater<lengths>> que;
    long long val = 0;
    for(int i=0; i<N; i++){
        val += A[i];
        lengths tmp = lengths(abs(sum-2*val), val);
        que.push(tmp);
    }

    lengths target = que.top();
    long long length = target.first;
    cout << length << endl;
    return 0;

}