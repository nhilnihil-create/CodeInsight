#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int k; cin >> k;
    string s; cin >> s;
    if(s.size()>k){
        rep(i,k) cout << s[i];
        cout << "..." << endl;
    }
    else cout << s << endl;
}