#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <cctype>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

locale l = locale::classic();

int main(){
    while(1){
        string s;
        cin >> s;
        ll ans=0;
        rep(i,s.size()){
            ans += s[i] - '0';
        }
        if(!ans) return 0;
        cout << ans << endl;
    }
}
