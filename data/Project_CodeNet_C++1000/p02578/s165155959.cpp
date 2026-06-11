#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maN = 1e6+5;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    
    for(int i = 0; i< n; ++i)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for(int i = 1; i < n; ++i)
    {
        if(a[i] < a[i-1] )
        {
            sum += a[i-1]-a[i];
            a[i] += a[i-1]-a[i];
        }
    }
    cout << sum;
	return 0;
}