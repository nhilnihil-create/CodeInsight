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
    
    rep(i, 5){
        int x;
        cin >> x;
        if (x - i == 1) continue;
        cout << (i + 1) << "\n";
    }
    
    return 0;
}

