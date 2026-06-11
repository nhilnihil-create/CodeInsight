#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

int main(){
    
    int k, a, b;
    cin >> k >> a >> b;
    
    if(a % k == 0){
        cout << "OK" << "\n";
    } else if(b / k - a / k > 0){
        cout << "OK" << "\n";
    } else {
        cout << "NG" << "\n";
    }
    
    return 0;
}
