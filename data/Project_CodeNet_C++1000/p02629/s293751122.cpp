#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long n,i,x;
string s;
int main() {
    cin >> n;
    s = "";
    while(n > 0) {
        if(n%26 == 0) {
            s += 'z';
            n /= 26;
            n--;
        } else {
            s += (char)('a'+n%26-1);
            n /= 26;
        }
    }
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}