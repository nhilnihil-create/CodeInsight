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
    int n;
    string s ;
    cin >> n >> s;
    if(s.size() <= n) {
        cout << s << endl;
        return;
    }else{
        cout << s.substr(0,n) << "..." << endl;
        return;
    }
}
int main() {
    _main();
    return 0;
}
    