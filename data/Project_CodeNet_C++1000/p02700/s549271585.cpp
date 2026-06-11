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
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if((a-1)/d < (c-1)/b){
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
    
    return 0;
}
