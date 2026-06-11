#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, k,ans = 1;
    cin >> n >> k;
    while(n >= k){
        n /= k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}