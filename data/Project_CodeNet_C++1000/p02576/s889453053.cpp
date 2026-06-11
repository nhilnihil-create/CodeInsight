#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maN = 1e6+5;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    int rem = n%k;
    int quo = n/k;
    int ans;
    if(rem > 0)
    {
        ans = t*(quo+1); 
    }
    else
    {
        ans = t*quo;
    }
    cout << ans;
    
	return 0;
}
