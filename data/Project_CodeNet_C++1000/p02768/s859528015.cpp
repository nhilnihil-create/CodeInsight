#include <bits/stdc++.h>
using namespace std;
long long int p = pow(10, 9) + 7;

long long int modPow(long long int a, long long int n){//繰り返し自乗法
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return a % p;
    }
    if (n % 2 == 1){ 
        return (a * modPow(a, n - 1)) % p;
    }      
    long long t = modPow(a, n / 2);
    return (t * t) % p;
}

long long int per(long long int x){//階乗 x!
    long long int res = 1;
    while(x > 0){
        res *= x;
        res = res % p;
        x--;
    }
    return res;
}

long long int perY(long long int x, long long int y){//nPy
    long long int res = 1;
    for(int i = 0; i < y; i++){
        res *= x;
        res = res % p;
        x--;
    }
    return res;
}

int main(){
    long long int n, a, b;
    cin >> n >> a >> b;
    long long result = modPow(2, n);//すべての数
    //cout << result << endl;

    long long tmp;
    tmp = per(a);
    tmp = modPow(tmp, p - 2);
    //cout << (perY(n, a) * tmp) % p << endl;
    result += p;
    result -= (perY(n, a) * tmp) % p;
    tmp = per(b);
    tmp = modPow(tmp, p - 2);
    //cout << (perY(n, b) * tmp) % p << endl;
    result += p;
    result -= (perY(n, b) * tmp) % p;
    
    result--;

    cout << result % p << endl; 
}