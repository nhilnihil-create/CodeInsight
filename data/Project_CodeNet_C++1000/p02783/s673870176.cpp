#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int h,a;
    cin >> h >> a;
    int ans=0;
    while(h>0){
        ans++;
        h-=a;
    }
    cout << ans << endl;
}
