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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(2019, 0);
    a[0] = 1;
    a[s[n-1] - '0'] = 1;
    int keta = 10;
    int tmp = s[n-1] - '0';
    long ans = 0;
    for(int i = 1; i < n; i++){
        tmp += ((s[n-1-i]-'0') * keta);
        tmp %= 2019;
        a[tmp] ++;
        keta = (keta*10) % 2019;
    }
    for(int i = 0; i < 2019; i++){
        ans += a[i]*(a[i]-1) / 2;
    }
    cout << ans << endl;
    return 0;
}



