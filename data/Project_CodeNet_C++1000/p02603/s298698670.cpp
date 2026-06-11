#include <bits/stdc++.h>
using namespace std;

void buy (long long& money, long long& stock, int price) {
    long long count = money / price;
    stock += count;
    money -= price * count;
}

void sell (long long& money, long long& stock, int price) {
    money += stock * price;
    stock = 0;
}

int main(void){
    int N;
    
    cin >> N;
    
    vector<long long> A(N);
    
    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    
    long long money = 1000;
    long long stock = 0;
    
    int mode = 0;
    for (int i = 0;i < N-1;i++){
        if (mode == 0) {
            if (A[i] <= A[i+1]) {
                buy(money, stock, A[i]);
                mode = 1;
            }
        } else if (mode == 1) {
            if (A[i] >= A[i+1]) {
                sell(money, stock, A[i]);
                mode = 0;
            }
        }
    }
    
    sell(money, stock, A[N-1]);
    cout << money << endl;

    return 0;    
}
