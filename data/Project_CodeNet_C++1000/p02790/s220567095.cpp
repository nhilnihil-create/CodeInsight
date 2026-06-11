#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int a,b;
    cin >> a >> b;
    string s,t;
    rep(i,b){
        s += to_string(a);
    }
    rep(i,a){
        t += to_string(b);
    }

    cout << min(s,t) << endl;
    return 0;
}