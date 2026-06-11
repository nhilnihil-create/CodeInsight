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
    
    string s;
    cin >> s;
    
    int l = s.size(), rem = 0, ans = 0, k = 10;
    vector<int> v(2020,0);
    v[0] = 1;
    
    for(int i = l - 1; i >= 0; i--){
        int x = s[i] - '0';
        rem = (x * k + rem) % 2019;
        ans += v[rem];
        v[rem]++;
        k = k * 10 % 2019;
    }
    
    cout << ans << "\n";
    
    return 0;
}
