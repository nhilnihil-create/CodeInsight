#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    long long wallet = 1000;
    long long lastPrice;
    cin >> lastPrice;
    N--;
    long long n;
    long long curPrice;
    while(N--) {
        cin >> curPrice;
        if(curPrice >= lastPrice) {
            n = wallet / lastPrice;
            wallet += n*(curPrice - lastPrice);
        } 
        lastPrice = curPrice;
    }
    cout << wallet;
    return 0;
}