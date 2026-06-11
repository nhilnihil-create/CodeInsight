#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long n;
    cin >> n;
    vector<long> a(n);
    for(long i = 0;i < n;i++){
          cin >> a[i];
    }
    for(long i = 0;i < n;i++){
          if(a[i] == 0){
                cout << 0 << endl;
                return 0;
          }
    }
    long t = 1;
    long limit = 1e18;
    for(long i = 0;i < n;i++){
          if(a[i] <= limit / t){
                t *= a[i];
          }else{
                cout << - 1 << endl;
                return 0;
          }
    }
    cout << t << endl;
}
