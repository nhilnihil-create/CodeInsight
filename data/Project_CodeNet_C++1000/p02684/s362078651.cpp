#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#include <cctype>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9
const ll llmax = pow(10, 18);


/*vector探索*/
// #define bSearch(v,k) binary_search(all(v),k)//ソートされた配列vの中の要素にkがあるか(boolean)
// #define lowB(v,k) lower_bound(all(v),k)//ソートされた配列vの中の要素のうちk以上かつ最小のイテレータ
// #define DLbetB(v,k) lowB(v,k)-v.begin()//先頭からの距離
// #define DLbetE(v,k) v.end()-lowB(v,k)//末尾からの距離
// #define uppB(v,k) upper_bound(all(v),k)//ソートされた配列vの中の要素のうちkより大きいかつ最小のイテレータ
// #define DUbetB(v,k) uppB(v,k)-v.begin()//先頭からの距離
// #define DUbetE(v,k) v.end()-uppB(v,k)//末尾からの距離
// #define Cnt(v,k) count(all(v),k)//配列vの中で要素kが何個あるかを返す(size_t)
// #define CntIf(v,l) count_if(all(v),l)//配列vの中で条件式(lambda式)を満たす個数を返す(ex.int num = count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});)
// #define Sort2D(myVec,i) sort(myVec.begin(),myVec.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[i] < beta[i];});//i列めでソート

/*最大公約数*/
// bool is_integer(double x){
//     return floor(x) == x;
// }

// vector<int> bitsearch(int n, int bit) {
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> S(n);
//         if(bit & (1 << i)){
//             S.push_back(i);
//         }
//     }
// }./  

/*あまり（強制的に正の余りを出力）*/
// void mod(ll &n,ll p){
//   n%=p;
//   if(n<0)n+=p;
// }
// ll rtmod(ll n,ll p){
//   mod(n,p);
//   return n;
// }


/*逆元　あまりの割り算をするときにこいつをかける(a/b→a*modinv(b))*/
// mod. m での a の逆元 a^{-1} を計算する
// ll modinv(ll a,ll m){
//     long long b = m, u = 1, v = 0;
//     while (b) {
//         long long t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= m;
//     if (u < 0) u += m;
//     return u;
// }



// bool IsPrime(ll num)
// {
//     if (num < 2) return false;
//     else if (num == 2) return true;
//     else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
 
//     double sqrtNum = sqrt(num);
//     for (int i = 3; i <= sqrtNum; i += 2)
//     {
//         if (num % i == 0)
//         {
            // 素数ではない
//             return false;
//         }
//     }
 
    // 素数である
//     return true;
// }
 
 /*階乗*/
// ll facctorialMethod(ll k){
//     ll sum = 1;
//     for (ll i = 1; i <= k; ++i)
//     {
//         sum *= i;
        //sum%=MOD;//あまりを出力せよ問題の時はこれもやる
//     }
//     return sum;
// }

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        // A[i] --;
    }

    // cout << N << "," << K << endl;
    // for (auto &&z : A)
    // {
    //     cout << z << ",";
    // }
    
    // cout << endl;
    

    // ループを調べる, 10^18回繰り返すから絶対にループするはず
    map<int, int> ROOP;
    int s, e, l, m; // ループスタート回数と終わりの回数,ループの長さ, ループが始まる街
    int a = 1; // aは街の番号
    map<int, int> Time;
    Time[1] = 0;
    
    if(K <  N){
        int huzakenna = 1;
        for (int i = 0; i < K; i++)
        {
            huzakenna = A[huzakenna];
            // cout << huzakenna << endl;
        }
        cout << huzakenna << endl;
        return 0;
    }

    for (int i = 1; i <= N + 1; i++) // N+1回繰り返す
    {   
        
        

        // 終了条件

        if(ROOP[A[a]] != 0){
            m = A[a];
            s = ROOP[A[a]];
            e = i;
            l = e - s; // 周期
            break;
        }

        ROOP[a] = i - 1;
        // 更新
        a = A[a];

    }

    // cout <<"s" <<s <<  ",e"<<e <<",l"<<l<< endl;

    vector<int> B(l); // ループ用配列
    B[0] = m;
    for (int i = 1; i < l; i++)
    {
        B[i] = A[B[i - 1]];
    }
    


    // for (auto &&i : B)
    // {
    //     cout << i <<",";
    // }
    


    // 答え
    int k;
    k = (K - s) % l;
    // cout << "繰り返し" << k << endl;

    int ans;
    ans = B[k]; // 繰り返しの何番目

    
    cout << ans << endl;
    
}
