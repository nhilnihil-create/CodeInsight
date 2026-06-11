#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string a;
    int ans = 0;
    cin >> a;
    
    if (a.at(0) == 'S') {
        ans = 0;
        if (a.at(1) == 'R') { 
            ans = 1;
            if (a.at(2) == 'R') ans = 2;
        } else {
            if (a.at(2) == 'R') ans = 1;
        }
    } else {
        ans = 1;
        if (a.at(1) == 'R') { 
            ans = 2;
            if (a.at(2) == 'R') ans = 3;
       }
    }
    
    cout << ans << endl;
}