#include <bits/stdc++.h>

using namespace std;

int main() {
    int d,t,s;
    cin >> d >> t >> s;
    int tt = (d+s-1)/s;
    if(tt > t)
        cout << "No\n";
    else 
        cout << "Yes\n";
}