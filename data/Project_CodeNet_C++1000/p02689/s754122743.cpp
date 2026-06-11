#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (int) 1e9 + 7;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> h(n,0), ans(n,1);
    rep(i,n) cin >> h[i];
    
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        if(h[a] > h[b]){
            ans[b] = 0;
        } else if(h[a] < h[b]){
            ans[a] = 0;
        } else {
            ans[a] = 0;
            ans[b] = 0;
        }
    }
    
    int count = 0;
    
    rep(i,n) if(ans[i] == 1) count++;
    
    cout << count << "\n";
    
    return 0;
}

