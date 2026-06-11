#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long n;
    cin >> n;
    vector<long> a(n);
    long Sum = 0;
    for(int i = 0;i < n;i++){
          cin >> a[i];
          Sum += a[i];
    }
    
    long ans = Sum;
    long t = 0;
    for(int i = 0;i < n;i++){
          t += a[i];
          ans = min(ans,abs(Sum - 2 * t));
    }
    cout << ans << endl;
    
}
