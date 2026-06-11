#include <stack>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;
int gcd(int a, int b)//最大公約数
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
vector<int> divisor(int n) {//約数発見
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    //std::stack<int> stack;
    int n;
    cin >> n;
    int ans = 1;
    vector<string> s(n);
    vector<int> cnt(10000000, 0);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    std::sort(s.begin(), s.end());
    for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}




