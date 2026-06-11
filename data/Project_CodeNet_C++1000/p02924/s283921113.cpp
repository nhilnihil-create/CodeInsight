#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    //i =  1, 2, 3
    //P =  2, 3, 1
    ll n;
    cin >> n;
    cout << n*(n-1)/2 << endl;
    return 0;
}

