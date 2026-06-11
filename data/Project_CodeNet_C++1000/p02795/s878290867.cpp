#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    int h,w,n;
    cin >> h >> w >> n;
    int m = h > w ? h : w;
    int ans = n / m;
    if(n % m != 0) ans++;
    cout << ans << endl;
    return 0;
}