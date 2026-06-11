#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    long long H;
    long long ans = 0;
    cin >> H;
    for(int i=0;H > 0;i++){
        H /= 2;
        long long num = 1;
        num = num << i;
        ans += num;
    }
    cout << ans << endl;
}
