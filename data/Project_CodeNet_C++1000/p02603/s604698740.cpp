#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int stock = 0, money = 1000, n, a[80];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]){
            //buy all
            stock += money / a[i];
            money %= a[i];
        } else if(a[i] > a[i+1]){
            //sell all
            money += a[i] * stock;
            stock = 0;
        }
    }
    //sell all
    money += a[n-1] * stock;
    stock = 0;
    cout << money << endl;
    return 0;
}