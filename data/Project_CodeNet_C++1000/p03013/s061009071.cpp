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
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];
    vector<ll> move(N + 1, -1);//0段目からN段め
    move[0] = 1;
    move[1] = 1;
    for(int a : A) move[a]=0;
    for(int i = 2; i < N + 1; i++){
        if(move[i] == -1){
             move[i] = move[i - 1] + move[i - 2];
             move[i] %= MOD7;
        }
    }
    if(move.back() == -1) puts("0");
    else cout << move.back() << endl;

}