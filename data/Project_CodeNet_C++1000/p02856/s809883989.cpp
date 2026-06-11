#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int m;
    cin >> m;
    ll d, c;
    ll digit_sum = 0, digit_nums = 0;
    while(m--) {
        cin >> d >> c;
        digit_sum += d*c;
        digit_nums += c;
    }
    ll target = (digit_sum - 1) % 9 + 1;
    cout << (digit_sum - target) / 9 + (digit_nums-1) << endl;

    return 0;
}


