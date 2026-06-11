#include <iostream>
#include <string>
using namespace std;


int main(void){
    long long n, a, b;
    cin >> n >> a >> b;
    
    long long ans;
    long long rep_times = n / (a+b);
    long long res_number = n - rep_times * (a + b);
    
    if (res_number >= a) ans = a * rep_times + a;
    else ans = a * rep_times + res_number; 
    cout << ans << endl;
}
