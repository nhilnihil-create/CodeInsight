#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a,b;
    cin >> a >> b;
    long long int c = a/b;
    cout << min(abs(a-b*c),abs(a-b*(c+1))) << endl;
}
