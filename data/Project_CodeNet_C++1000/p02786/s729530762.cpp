#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t h;
    cin >> h;
    int64_t ans = 0;
    int64_t count = 1;
    while(true){
        ans += count;
        count *= 2;
        if(h==1)break;
      	h/=2;
    }

    cout << ans << endl;
    return 0;
}