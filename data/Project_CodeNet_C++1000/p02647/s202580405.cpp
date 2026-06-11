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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = min(k, (int)log(200000)+1);
    for(int i = 0; i < k; i++){
        vector<int> b(n,0);
        for(int j = 0; j < n; j++){
            int left = max(0, j-a[j]);
            int right = min(n-1, j+a[j]);
            b[left] ++;
            if(right < n-1){
                b[right+1] --;
            }
        }
        for(int j = 1; j < n; j++){
            b[j] += b[j-1];
        }
        if(a == b){
            break;
        }
        a=b;
    }
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    //cout << ans << endl;
    return 0;
}



