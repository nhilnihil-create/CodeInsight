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
    
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(1000001, 0);
    vector<int> c(1000001, 1);
    

    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        b[x]++;
    }
    
    sort(a.begin(), a.end());
    
    rep(i, n){
        
        if(c[a[i]] == 0) continue;
        if(i > 0 && a[i] == a[i - 1]) continue;
        
        for(int j = 2; j < 1000001; j++){
            if (j * a[i] > 1000000) break;
            c[a[i] * j] = 0;
        }
    }

    int count = 0;

    rep(i, n) if(b[a[i]] == 1 && c[a[i]] == 1) count++;
    
    cout << count << "\n";

    return 0;
}


