#include <bits/stdc++.h>
using namespace std;
#define COUNTOF(array)  (sizeof(array) / sizeof(array[0]))
typedef long long ll;
typedef vector<int> VI;
typedef vector<string> VS;
using P = pair<int,int>;

int main() {
    int N , X , T;
    cin >> N >> X >> T;

    int temp = N / X;

    if(N % X != 0)  temp ++;

    int ans = temp * T;

    cout << ans << endl;

    return 0;
}