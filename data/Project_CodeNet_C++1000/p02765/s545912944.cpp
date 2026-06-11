#include <iostream>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    
    int ans = m;
    if (n <= 10) {
      ans = 100 * (10-n) + m;
    }
    
    cout << ans << endl;
}