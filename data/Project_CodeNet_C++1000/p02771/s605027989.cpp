#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if (a == b && a != c)ans = true;
    if (b == c && b != a)ans = true;
    if (c == a && c != b)ans = true;
    if (ans)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}