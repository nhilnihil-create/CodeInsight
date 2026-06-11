#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long b[n-1];

    for(long long i = 0; i < n-1; i++){
        cin >> b[i];
    }

    long long sum = 0;
    for(long long i = 0; i < n; i++){
        if(i == 0){
            sum += b[i];
            continue;
        }

        if(i == n-1){
            sum += b[i-1];
            continue;
        }

        sum += min(b[i-1], b[i]);
    }
    cout << sum << endl;
    return 0;
}