#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
    long long X;
    cin >> X;
    while(true) {
        if(IsPrime(X) == true) {
            cout << X << endl;
            exit(0);
        }
        X++;
    }

}