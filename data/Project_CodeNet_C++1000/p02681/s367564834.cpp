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
    
    string s, t;
    cin >> s >> t;
    
    if(t.size() - s.size() != 1){
        cout << "No" << "\n";
    }
    
    rep(i,s.size()) if(s[i] != t[i]){
        cout << "No" << "\n";
        return 0;
    }
    
    cout << "Yes" << "\n";

    
    return 0;
}
