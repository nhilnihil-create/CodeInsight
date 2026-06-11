#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int count, n;
    count = n = 0;
    string s;
    cin >> n >> s;
    for(int i=0; i<n-2;++i) {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}