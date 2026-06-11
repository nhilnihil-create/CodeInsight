#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//1000000000000000000
//124999999999999995
long long cnt5(long long n){
    long long ret = 0 ;
    while(n){
        n/=5;
        ret+=n;
    }
    return ret;
}
int main()
{
    long long n;
    cin >> n;
    if(n%2)
        cout << 0 << endl;
    else{
        long long sum = cnt5(n/2);
        long long num  =1;
//        for(int i=1;i<=n/10;i++){
//            cout << i*10 << endl;
//        }

        cout << sum <<endl;
        //int dd = 0;

    }
    return 0;
}
