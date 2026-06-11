#include <bits/stdc++.h>
using namespace std;
int main() {int a, b; cin >> a >> b; cout << min(string(a, b + '0'), string(b, a + '0')) << endl;}