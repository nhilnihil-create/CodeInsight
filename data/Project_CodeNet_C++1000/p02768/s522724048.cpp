#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;


long long RepeatSquare(long long n, long long p, long long m){
    if(p == 0) return 1;
    if(p%2 == 0){
        long long t = RepeatSquare(n, p/2, m);
        return t * t %m;
    }
    return n * RepeatSquare(n, p-1, m) %m;
}

long long choose(long long a, long long b, long long m)
{
    long long up = 1, lo = 1;
    for (int i = 0; i < b; i++)
    {
        up = up * ((a - i) % m) %m;
        lo = lo * ((b - i) % m) %m;
    }
    
    long long tmp = RepeatSquare(lo, m-2, m);
    //cout << "tmp" << tmp << endl;
    return up * tmp %m;
    //return up / lo %m;
}

int main(int argc, char const *argv[])
{
    long long n, a, b;
    long long mod = 1000000007;
    cin >> n >> a >> b;
    long long sum = (RepeatSquare(2, n, mod) -1) % mod;

    if(b > a){
        swap(a,b);
    }
    long long num = 0;
    long long a1 = choose(n, a, mod);
    long long b1 = choose(n, b, mod);
    //cout << "a1: " << a1 << " b1: " << b1 << endl;
    num = ((sum - a1) % mod - b1) %mod;
    long long ans = 0;
    if(num < 0)
        ans = num + mod;
    else{
        ans = num;
    }
    cout << ans << endl;

    return 0;
}
