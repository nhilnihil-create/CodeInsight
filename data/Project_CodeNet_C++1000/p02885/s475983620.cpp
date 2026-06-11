#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    
    int a,b;
    cin >> a >> b;
    int x;
    x = b * 2;
    if(a > x)
        {
        int ans;
        ans = a-x;
        cout << ans << endl;
        }
    else
        cout << "0" << endl;
        
}
