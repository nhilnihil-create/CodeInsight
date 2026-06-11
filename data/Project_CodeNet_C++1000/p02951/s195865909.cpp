#include <iostream>
using namespace std;
int main(void){
    
    int a,b,c;
    cin >> a >> b >> c;
    int x;
    x = b +c;
    
    if(a < x )
        {
        int ans;
        ans = x - a;
        cout << ans << endl;
        }
    else
        cout << "0" << endl;

}
