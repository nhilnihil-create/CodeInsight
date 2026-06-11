#include <iostream>
using namespace std;
int main(void){
    
    int a,b,c;
    cin >> a >> b;
    
    if(a <= 9 && b <= 9)
        {
        int ans;
        ans = a * b;
        cout << ans << endl;
        }
    else
        cout << "-1" << endl;

}
