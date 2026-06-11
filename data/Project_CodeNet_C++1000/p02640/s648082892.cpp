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
    
    int x, y;
    cin >> x >> y;
    
    if (y % 2 > 0){
        cout << "No" << "\n";
        return 0;
    }
    
    int z = y / 2 - x;
    
    if (z >= 0 && z <= x){
        cout << "Yes" << "\n";
        return 0;
    }

    cout << "No" << "\n";
    return 0;

    return 0;
}

