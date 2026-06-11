#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int A[210000], B[210000];

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
        if(B[i] < A[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    long long int ans = 0;
    queue<int> que;
    for(int i = 0; i < N; i++){
        if(B[(i - 1 + N) % N] < B[i] && B[i] > B[(i + 1) % N]){
            que.push(i);
        }
    }
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        long long int S = B[(pos - 1 + N) % N] + B[(pos + 1) % N];
        ans += (B[pos] - A[pos]) / S;
        B[pos] -= (B[pos] - A[pos]) / S * S;
        if(B[(pos - 2 + N * 2) % N] < B[(pos - 1 + N) % N] && B[(pos - 1 + N) % N] > B[pos]){
            que.push((pos - 1 + N) % N);
        }
        if(B[pos] < B[(pos + 1) % N] && B[(pos + 1) % N] > B[(pos + 2) % N]){
            que.push((pos + 1) % N);
        }
    }
    for(int i = 0; i < N; i++){
        if(A[i] != B[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}