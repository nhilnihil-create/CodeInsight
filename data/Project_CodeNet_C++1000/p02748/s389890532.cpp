#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long a, b, m;
    cin >> a >> b >> m;

    long long A[a], B[b];

    long long min_a = 1e9, min_b = 1e9;

    for(long long i = 0; i < a; i++){
        cin >> A[i];
        min_a = min(min_a, A[i]);
    }

    for(long long i = 0; i < b; i++){
        cin >> B[i];
        min_b = min(min_b, B[i]);
    }

    long long min_cost = min_a + min_b;

    for(long long i = 0; i < m; i++){
        long long x, y, c;
        cin >> x >> y >> c;
        min_cost = min(min_cost, A[x-1]+B[y-1]-c);
    }
    cout << min_cost << endl;
    return 0;
}