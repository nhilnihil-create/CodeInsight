#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
long long n,i,x;
vector<long long> v;
int main() {
  /*  cin >> n;
    s = "";
    while(n > 1) {
        if(n%26 == 0) s += 'z';
        else s += (char)('a'+n%26-1);
        n /= 26;
    }
    
    if(n == 1) s = "a" + s;
    cout << s;*/
    cin >> n;
    v.resize(n);
    x = 0;
    for(i = 0; i < n; i++) {
        cin >> v[i];
        x ^= v[i];
    }
    for(i = 0; i < n; i++) {
        cout << (x^v[i]) << " ";
    }
    cout << endl;
    return 0;
}