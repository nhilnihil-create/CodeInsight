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
    
    int n;
    cin >> n;
    vector<int> v(n + 1,0);
    
    rep(i,n - 1){
        int a;
        cin >> a;
        v[a]++;
    }
    
    rep(i,n){
        cout << v[i + 1] << "\n";
    }
    
    return 0;
}
