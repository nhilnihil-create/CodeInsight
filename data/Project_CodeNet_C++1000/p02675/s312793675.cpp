#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int a = t%10;
    if (a == 2 || a == 4 || a == 5 || a == 7 || a == 9)
        cout<<"hon\n";
    else if (a == 0 || a==1 || a==6||a==8)
        cout << "pon\n";
    else  cout << "bon\n";
}
