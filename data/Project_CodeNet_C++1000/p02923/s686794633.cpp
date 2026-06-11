#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    if(N == 1){
        puts("0");
        return 0;
    }
    vector<int> move_n(N);
    int move = 0;
    for(int i = N - 1; i>= 1; i--){
        move_n[i] = move;
        if(H[i-1] >= H[i]) move++;
        else move = 0;
    }
    if(H[0] >= H[1]) move_n[0] = move_n[1]+1;
    else move_n[0] = 0;
    
    int max_n = 0;
    for(int a : move_n) max_n = max(max_n, a);
    cout << max_n<< endl;
}