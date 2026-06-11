
#include <iostream>                                                
#include <vector>  
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#define endl "\n"

using ll = long long;
using namespace std;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
    
        
    
    return 0;
}
