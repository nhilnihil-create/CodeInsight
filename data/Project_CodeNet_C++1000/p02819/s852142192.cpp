#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

bool IsPrime(long num){
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
    long x;
    cin>>x;
    if(x==2){
        cout<<2<<endl;
        return 0;
    }else if(x%2==0) x++;
    for(long i=x;i<2*x;i+=2){
        if(IsPrime(i)){
            cout<<i<<endl;
            return 0;
        } 
    }
}