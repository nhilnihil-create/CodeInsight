#include <iostream>
#include <vector>

using namespace std;
int main(void){
    long n;
    cin >> n;
    vector<long> a(n + 1);
    vector<long> b(n);
    
    for(int i = 0;i < n + 1;i++){
          cin >> a[i];
    }
    for(int i = 0;i < n;i++){
          cin >> b[i];
    }
    long ans = 0;
    for(int i = 0;i < n;i++){
          int t = min(a[i],b[i]);
          ans += t;
          b[i] -= t;
          t = min(a[i + 1],b[i]);
          ans += t;
          a[i + 1] -= t;
          
    }
    cout << ans << endl;
}
