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
    
    string s;
    cin >> s;
    rep(i,3){
        if(s[i] == '7'){
            cout << "Yes" << "\n";
            return 0;
        }
    }
    
    cout << "No" << "\n";
    
    return 0;
}

