#include <iostream>

using namespace std;

int digits_sum(int num) {
    int digit, sum = 0, base = 1000;
    
    while(base != 0) {
        digit = num / base;
        sum += digit;
        num -= base * digit;
        base /= 10;
    }
    
    return sum;
}

int main() {
    int n, res, cnt;
    
    while(cin >> n) {
        cnt = 0;
        
        for(int i = 0;i < 10000;i++) {
            res = digits_sum(i);
            
            if(res == n) {
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
