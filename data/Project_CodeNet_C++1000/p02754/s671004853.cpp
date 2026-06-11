#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    int n,a,b;
    int num;
    int ans = 0;
    int sur;
    cin >> n >> a >>b;
    num = n/(a+b);
    sur = n%(a+b);
    
    ans += num*a;
    if(sur > a) ans += a;
    else ans+= sur;
    
    cout << ans;
    
    return 0;
}