#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n)cin >> h[i];

    int ans = 0;
    int cnt = 0;
    
    reps(i,0,n-1){
        if(h[i] >= h[i+1]){ 
            cnt++;
        }else {
            //cout << cnt << endl;
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    cout << max(cnt,ans) << endl;
    return 0;
}