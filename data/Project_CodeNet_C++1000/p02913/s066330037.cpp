#include<iostream>

using ull = unsigned long long;
using namespace std;

#define B1 100000007
#define B2 1000000007

bool rolling_hash(string const &S, int t_start, int m){
    int s_start = t_start + m;

    // B^mを用意する
    ull pow_B_m_1 = 1, pow_B_m_2 = 1;
    for(int k = 0; k < m; k++){
        pow_B_m_1 *= B1, pow_B_m_2 *= B2;
    }

    // sとtの先頭m文字のハッシュ値sh,thを計算
    ull sh1 = 0, sh2 = 0, th1 = 0, th2 = 0;
    for(int k = 0; k < m; k++){
        th1 = th1 * B1 + S[t_start + k], th2 = th2 * B2 + S[t_start + k];
        sh1 = sh1 * B1 + S[s_start + k], sh2 = sh2 * B2 + S[s_start + k];
    }

    // sをずらしてハッシュ値を更新
    for(int k = 0; s_start + m + k < S.length(); k++){
        if(sh1 == th1 && sh2 == th2) return true;
        sh1 = sh1 * B1 + S[s_start + m + k] - S[s_start + k] * pow_B_m_1;
        sh2 = sh2 * B2 + S[s_start + m + k] - S[s_start + k] * pow_B_m_2;
    }
  	if(sh1 == th1 && sh2 == th2) return true;
    return false;
}

int main(){
    int n; string S;
    cin >> n >> S;

    // 一致する最大文字数を２分探索
    int ng = n+1, ok = 0, mid;
    while(ng - ok > 1){
        mid = (ng + ok) / 2;
        bool mached = false;
        // Sのi文字目をtの先頭として,t = S[i:i+mid], s = S[i+mid:n]
        for(int i = 0; i <= n - mid*2; i++){
            if(rolling_hash(S, i, mid)){
                mached = true;
                break;
            }
        }
        if(mached) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}