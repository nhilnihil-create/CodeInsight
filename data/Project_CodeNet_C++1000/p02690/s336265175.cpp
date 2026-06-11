#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (int) 1e9 + 7;

int main(){
    
    long x;
    cin >> x;
    
    for(long i = -200; i < 200; i++){
        for(long j = -200; j < i; j++){
            long ii = i * i * i * i * i;
            long jj = j * j * j * j * j;
            if(ii - jj == x){
                cout << i << ' ' << j << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}

