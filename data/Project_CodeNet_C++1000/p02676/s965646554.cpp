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
    
    int k;
    string s;
    cin >> k >> s;
    
    if(k >= s.size()){
        cout << s;
    } else {
        rep(i,k) cout << s[i];
        cout << "...";
    }
    
    cout << "\n";
    
    return 0;
}
