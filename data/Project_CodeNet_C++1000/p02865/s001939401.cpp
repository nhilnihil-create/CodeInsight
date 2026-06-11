#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << n/2 - 1 << endl;
    else
        cout << n/2 << endl;
    return 0;
}


