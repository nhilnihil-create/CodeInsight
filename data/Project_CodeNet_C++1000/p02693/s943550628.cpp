#define _GLIBCXX_DEBUG
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int16_t k,a,b;
    bool f = false;
    cin >> k;
    cin >> a >> b;
    for (int i = a; i<=b; i++) {
        if (i%k == 0){
            f = true;
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
}