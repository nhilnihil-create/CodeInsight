#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define begin begin()
#define end end()

void _main(){
    string s; cin >> s;
    //int n ; cin >> n;
    int n = (s.size()-1)/2;
    string left,right;
    left  = s.substr(0,n);
    right = s.substr(n+1,n);
    auto kaibun = [](string s){
        int n = s.size()/2;
        rep(i,n){
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    };
    if(kaibun(s) && kaibun(left) && left == right){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return;
}
int main() {
    _main();
    return 0;
}
    