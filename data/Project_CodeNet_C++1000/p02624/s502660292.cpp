#include <iostream>
#include <cstdint>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int64_t sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            sum += j;
        }
    }
    cout << sum << '\n';
    return 0;
}