#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;
    string b;
    cin >> a >> b;

    long long bll = (b[0]-'0')*100 + (b[2]-'0')*10 + (b[3]-'0');
    cout << a*bll/100 << endl;
}