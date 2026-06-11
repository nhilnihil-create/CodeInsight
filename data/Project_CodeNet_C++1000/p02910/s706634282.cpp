#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int N = (int)s.size();
    bool is = true;
    rep(i, N){
        if(i % 2 == 0){
            if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D') is = false;
            else continue;
        }else if(i % 2 == 1){
            if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D') is = false;
            else continue;
        }
    }
    if(is) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}