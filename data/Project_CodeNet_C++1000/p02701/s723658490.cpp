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
    
    int n;
    cin >> n;
    set<string> S;
    
    rep(i,n){
        string s;
        cin >> s;
        S.emplace(s);
    }
    
    cout << S.size() << "\n";
    
    return 0;
}
