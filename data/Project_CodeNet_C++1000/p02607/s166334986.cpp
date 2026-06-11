#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    int out = 0, temp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(i&1 && temp&1)
            out++;
    }
    cout << out;
}