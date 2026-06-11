#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    long long tap = 1;
    while(tap < b){
        ans++;
        tap += a-1;
    }
    cout << ans << endl;
    return 0;
}