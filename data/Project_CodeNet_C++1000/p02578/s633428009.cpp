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
    vector<ll> def(n,0);
    ll sum = 0;
    
    def[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        if(a[i] < a[i-1] && def[i-1] == 0)
        {
            def[i] = a[i-1]-a[i];
            sum += def[i];
        }
        else if(def[i-1] != 0)
        {
            ll cur_he = def[i-1] + a[i-1];
            if(cur_he > a[i])
            {
                def[i] = cur_he - a[i];
                sum += def[i];
            }
        }
    }
    cout << sum;
	return 0;
}






