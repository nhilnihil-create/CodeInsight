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
    
    int s, w;
    cin >> s >> w;
    
    if(w >= s){
        cout << "unsafe" << "\n";
    } else {
        cout << "safe" << "\n";
    }
    
    return 0;
}
