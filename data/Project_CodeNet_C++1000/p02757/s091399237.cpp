#include <iostream>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;
 
typedef long long ll;
 
int mod;
int sub(int i, int j) { return ((i -= j) < 0 ? i += mod : i); }
int add(int i, int j) { return ((i += j) < mod ? i : i -= mod); }
int mult(int i, int j) { return (ll) i * j % mod; }
 
int A[200000];
int box[100000];
 
int main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int n; cin >> n >> mod;
    string line; cin >> line;
    reverse(line.begin(), line.end());
    for(char& c : line)
        c -= 48;
    
    if(mod == 2 || mod == 5) {
        ll mx = 0;
        for(int i = 0; i < n; ++i)
            if(line[i] % mod == 0)
                mx += n - i;
                
        cout << mx;
        return 0;
    }
     
    int r = 1;
    A[0] = line[0] % mod;
    for(int i = 1; i < n; ++i) {
        r = mult(r, 10);
        A[i] = add(mult(r, line[i]), A[i - 1]);
    }
    
    for(int i = 0; i < n; ++i)
        box[A[i]] += 1;
    
    int rx = 0;
    r = 1;
    ll res = box[0];
    for(int i = 0; i < mod; ++i)
        res += (ll) box[i] * (box[i] - 1) / 2;
    
    cout << res;
    return 0;
}