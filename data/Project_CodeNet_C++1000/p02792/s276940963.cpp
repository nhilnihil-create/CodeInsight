#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(10,vector<int> (10,0));

    for (int i = 1;i <= n;i++){
        string s;
        s = to_string(i);
        v[stoi(s.substr(0,1))][stoi(s.substr(s.size()-1,1))]++;
    }
    ll ans = 0;
    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 10;j++){
            ans += ll(v[i][j])*v[j][i]; 
        }
    }
    cout << ans << endl;
    
   return 0;

}