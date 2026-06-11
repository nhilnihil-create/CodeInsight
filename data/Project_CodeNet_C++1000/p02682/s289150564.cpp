
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    long a, b, c, k;
    cin >> a >> b >> c >> k;
    
    if(k <= a){
        cout << k << "\n";
        return 0;
    } else if(k <= a + b){
        cout << a << "\n";
        return 0;
    } else {
        cout << (2 * a - k + b) << "\n";
        return 0;
    }
    
    return 0;
}
