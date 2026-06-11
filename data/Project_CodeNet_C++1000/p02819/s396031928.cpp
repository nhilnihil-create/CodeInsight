#include <bits/stdc++.h>
bool IsPrime(int num)
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
using namespace std;
int main(void){
    long long int n,x,i=0,h[200000],ans=0,c=0;
    string s;
    cin >> x;
    while(1)
    {
        if(IsPrime(x))
        {
            cout << x << endl;
            return 0;
        }
        x++;
    }
    return 0;
}
