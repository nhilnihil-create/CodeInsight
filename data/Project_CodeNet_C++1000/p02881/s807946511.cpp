#include <bits/stdc++.h>
using namespace std;

#include <math.h> 

bool IsPrime(long long int num)
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
int main(void){
    long long int c=0,n,a[3],saisyo=1000000001900;
    {
        cin >> n;
    }
    if(IsPrime(n)==true)
    {
        cout << n-1 << endl;
        return 0;        
    }
    long long int i=2,j=2;
    for(i=2;i<n/2+1;i++)
    {
        if(n/i*i==n && saisyo>n/i+i-2)
        {
            saisyo=n/i+i-2;
            c++;
        }
        if(saisyo<i)
        {
            break;
        }
        if(i*i>n)
        {
            break;
        }
    }
    cout << saisyo << endl;
    return 0;
}
