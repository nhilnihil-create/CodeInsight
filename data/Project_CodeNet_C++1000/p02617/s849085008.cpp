#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long nodes = 0, edges = 0;
    for(long long i = 1; i <= n; i++){
        nodes = nodes + i * (n - i + 1);
    }
    for(long long i = 1; i < n; i++){
        long long u, v;
        cin >> u >> v;
        long long a = min(u, v), b = max(u, v);
        edges = edges + a * (n - b + 1);
    }
    cout << nodes - edges;
    return 0;
}