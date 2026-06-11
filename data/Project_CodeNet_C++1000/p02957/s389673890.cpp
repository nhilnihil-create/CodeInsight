#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
#define ll long long
int main(void){

    ll num1, num2;
    scanf("%lld%lld", &num1, &num2);
    ll mid = (num1+num2)>>1;
    if(abs(num1 - mid)==abs(num2 - mid)){
        cout << mid;
    } else {
        cout <<"IMPOSSIBLE\n";
    }
    return 0;
}