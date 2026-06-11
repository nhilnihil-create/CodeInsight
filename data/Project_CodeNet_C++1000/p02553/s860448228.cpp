    #include <iostream>
    #include <vector>
    #include <algorithm>
     
    using namespace std;
     
    #define int long long
     
    int32_t main() {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	cout << max(a * c, max(b * d, max(a * d, b * c)));
    }