#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int MAXN = 2e5 + 5;
int N, K, C, a[MAXN], b[MAXN];
string s;
int main(){
    cin >> N >> K >> C;
    cin >> s;
    int u = 0, v = K - 1;
    for (int i = 0; i < N; ++ i){
            if (s[i] == 'o') {a[u++] = i; i += C;}
            if (u == K) break;
    }
    for (int i = N - 1; i >= 0; -- i){
        if (s[i] == 'o') {b[v--] = i; i -= C;}
        if (v == -1) break;
    }
    for (int i = 0; i < K; ++ i){
        if (a[i] == b[i]) cout << a[i] + 1<< endl;
    }
    return 0;
}
