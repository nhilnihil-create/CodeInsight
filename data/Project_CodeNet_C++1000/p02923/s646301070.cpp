#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i = 0; i < n; i++) cin >> h[i];
    h[n] = h[n-1]+1;
    int ans = 0;
    for(int i = 1, start = 0; i <= n; i++){
        if(h[i-1] >= h[i]){
            ;
        }else{
            if(i-start-1 > ans) ans = i-start-1;
            start = i;
        }
    }
    cout << ans << endl;
    return 0;
}