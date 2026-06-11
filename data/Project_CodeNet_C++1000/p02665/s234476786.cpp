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
long nc2(long n){
    return n*(n-1)/2;
}
template<typename TypeInt>
std::string Itoa(const TypeInt v, int base)
{
	static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ret;
	static numeric_limits<TypeInt> t;
	TypeInt n = v;
	if (t.is_signed) {
		if (v < 0) n *= -1;
	}

	while (n >= base) {
		ret += table[n%base];
		n /= base;
	}
	ret += table[n];
	if (t.is_signed) {
		if (v < 0 && base == 10) ret += '-';
	}
	// 文字列の順番を逆にする
	std::reverse(ret.begin(), ret.end());

	return ret;
}
int main(){
    //std::stack<int> stack;
    long n;
    cin >> n;
    vector<long> a(n+1);
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    long ans = 0;
    long tmp = 1;
    vector<long> sum(n+2,0);
    sum[n] = a[n];
    for(int i = 1; i <= n; i++){
        sum[n-i] = sum[n-i+1] + a[n-i];
    }
    for(int i = 0; i <= n; i++){
        ans += tmp;
        tmp -= a[i];
        if(tmp < 0){
            cout << -1 << endl;
            return 0;
        }
        
        tmp = min(tmp*2, sum[i+1]);
    }
    cout << ans << endl;
    return 0;
}




