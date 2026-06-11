#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    int ans = 0;

    cin >> a >> b >> c;
    
    ans = c - (a - b);
    if (ans < 0) ans = 0;

    cout << ans << endl;

return 0;
}