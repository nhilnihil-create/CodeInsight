#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, x, y;
    cin >> n >> x >> y;

    x--;
    y--;

    vector<long long> result(n ,0);

    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            long long k = min(abs(i-j), abs(i-x)+1+abs(y-j));
            result[k]++;
        }
    }

    for(long long k = 1; k < n; k++){
        cout << result[k] << endl;
    }

    return 0;
}