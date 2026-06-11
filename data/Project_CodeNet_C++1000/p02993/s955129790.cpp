#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {    
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++) {
        if(s[i] == s[i+1]) {
            puts("Bad");
            return 0;
        }
    }
    puts("Good");
    return 0;
}
