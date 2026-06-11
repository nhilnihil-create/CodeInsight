#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b, c, ans;
    cin >> a >> b >> c;
    
    ans = c - ( a - b);
    if(ans >0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    
}
