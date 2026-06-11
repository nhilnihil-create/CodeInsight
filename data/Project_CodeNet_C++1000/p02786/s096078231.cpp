#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Count(ll input){
    
    ll sum = 0;
    while(input){
        input/= 2;
        sum++;
    }
    return sum;
}
int main(){

    ll H; cin >> H;
    printf("%.0f\n",pow(2,Count(H))-1);
}