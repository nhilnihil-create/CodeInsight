#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long pow2(long long a, long long b){
    long long ret = 1;
    while(b > 0){
        if(b % 2 == 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return ret;
}
 
long long mul(int s, int e){
    long long ret = 1;
    for(int i = s; i <= e; i++){
        ret = ret * i % MOD;
    }
    return ret;
}
 
long long fact(int n){
    return mul(1, n);
}
 
long long nCr(int n, int r){
    return mul(n-r+1, n) * pow2(fact(r), MOD-2) % MOD;
}

int main()
{
    int x, y;
    cin >> x >> y;

    if((x + y) % 3 == 0)
    {
        if((x + y) / 3 <= x && x <= (x + y) * 2 / 3 && (x + y) / 3 <= y && y <= (x + y) * 2 / 3)
        {
            cout << nCr((x + y) / 3, x - (x + y) / 3) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        
    }
    else
    {
        cout << 0 << endl;
    }
    
}