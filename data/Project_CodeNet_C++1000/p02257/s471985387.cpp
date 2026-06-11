#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    int r;
    while (b > 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool isprime(int x){
    if (x == 2) return true;
    if (x < 2 || x % 2 ==0) return false;
    
    int i = 3;
    while(i <=  sqrt(x)){
        if (x % i == 0) return false;
        i +=  2;
    }
    return true;
}




int main() {
    int n, cnt=0;
    cin >> n;
    for (int i; i<n; i++) {
        bool judge;
        int num;
        cin >> num;
        judge=isprime(num);
        if(judge) cnt += 1;
    }
    cout << cnt << endl;
}


