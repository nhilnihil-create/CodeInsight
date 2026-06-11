#include <iostream>
using namespace std;
int main(void){
    int K,X;
    string ans = "Yes";
    cin >> K >> X;
    if(500 * K < X)ans = "No";
    cout << ans << endl;
}
