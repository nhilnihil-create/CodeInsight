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
    
    int x, n;
    cin >> x >> n;
    
    if(n == 0){
        cout << x << "\n";
        return 0;
    }
    
    set<int> s;
      
    rep(i, n){
        int a;
        cin >> a;
        s.insert(a);
    }
    
    rep(i, 100){
        int a = x - i;
        int b = x + i;
        if(s.count(a) == 1 && s.count(b) == 1) continue;
        
        if(s.count(a) == 0){
            cout << a << "\n";
            return 0;
        } else {
            cout << b << "\n";
            return 0;
        }
        
    }
 
    return 0;
}