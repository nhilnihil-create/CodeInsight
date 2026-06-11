#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s = "";
    
    while(n>0) {
        s += '0' + n % k;
        n/=k;
    }
    cout << s.size() << endl;
    
    
}