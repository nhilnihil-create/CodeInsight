#include <iostream>
#include <string>
using namespace std;
int main(){
    int a, b, c;
    string ans = "";
    cin >> a >> b >> c;
    if ((a == b && a != c) || (b == c && b != a) || (c == a && c != b)){
        ans = "Yes";
    }
    else ans = "No";
    cout << ans << endl;
}