#include <stack>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <iomanip>
#include <string>
using namespace std;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
int mod = 1000000000 + 7;
vector<int> v;
class Calc
{
    // 宣言
    long long a;

    public:
        // 素因数分解
        void decompositPrime(long long a);
};

/*
 * 素因数分解
 */
void Calc::decompositPrime(long long n)
{
    // 割る数の初期値
    a = 2;
    // √n ≧ a ( n ≧ a * a ) の間ループ処理
    while (n >= a * a) {
        // a で割り切れたら、a は素因数
        // そして、割られる数を a で割る
        // a で割り切れなかったら、 a を 1 増加させる
        if (n % a == 0) {
            //printf("%d * ", a);
             v.push_back(a);
            n /= a;
        } else {
            a++;
        }
    }
    // 最後に残った n は素因数
    v.push_back(n);
    //printf("%d\n", n);
}

int main(){
    //std::stack<int> stack;
    int n;
    cin >> n ;
    vector<long> a(n+1);
    vector<long> b(n+1);
    vector<long> um(n+2);
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    um[n] = a[n];
    for(int i = n-1; i >= 0; i--){
        um[i] = um[i+1] + a[i];
    }
    long ans = 0;
    b[0] = 1-a[0];
    long tmp = 1;
    for(int i = 0; i <= n; i++){
        ans += tmp;
        tmp -= a[i];
        if(tmp < 0){
            cout << -1 << endl;
            return 0;
        }
        tmp = min(tmp*2, um[i+1]);
    }
    cout << ans << endl;
    return 0;
}



