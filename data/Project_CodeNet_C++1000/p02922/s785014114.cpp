#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int a, b, ans=1;
    cin >> a >> b;
    if(b == 1) {
        cout << 0 << endl;
        return 0;
    }
    if(a >= b){
        cout << ans << endl;
        return 0;
    }
    while(true){
        if(a*ans-ans+1 >= b) break;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}