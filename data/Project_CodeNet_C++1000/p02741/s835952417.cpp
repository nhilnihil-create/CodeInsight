/* include */
#include"bits/stdc++.h"
/* namespace */
using namespace std;
/* typedef */
/* long系 */
typedef long long ll;	// long long
typedef long double ld;	// long double
/* vector系 */
typedef vector<int> vint;	// intのvector
typedef vector<double> vdouble;	// doubleのvector
typedef vector<ll> vll;	// llのvector
typedef vector<ld> vld;	// ldのvector
typedef vector<pair<int, int>> vi_i;	// i_iのvector
typedef vector<pair<double, double>> vd_d;	// d_dのvector
typedef vector<pair<ll, ll>> vl_l;	// l_lのvector
typedef vector<pair<ld, ld>> vld_ld;	// ld_ldのvector
typedef vector<string> vstring;	// stringのvector
/* pair系 */
typedef pair<int, int> i_i;	// int同士のpair
typedef pair<double, double> d_d;	// double同士のpair
typedef pair<ll, ll> l_l;	// ll同士のpair
typedef pair<ld, ld> ld_ld;	// ld同士のpair
/* define */
#define pb push_back	// push_back
#define all(v) v.begin(),v.end()	// コンテナ全体
#define PI (acos(-1))  // 円周率pi
/* 変数入出力 read, write */
template <typename T>	// 1変数
void read(T& x) {
    cin >> x;
}
template <typename T, typename T0>	// 2変数
void read(T& x, T0& y) {
    cin >> x >> y;
}
template <typename T, typename T0, typename T1>	// 3変数
void read(T& x, T0& y, T1& z) {
    cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>	// 4変数
void read(T& x, T0& y, T1& z, T2& w) {
    cin >> x >> y >> z >> w;
}
template <typename T>	// 1変数
void write(T& x) {
    cout << x << endl;
}
template <typename T, typename T0>	// 2変数
void write(T& x, T0& y) {
    cout << x << " " << y << endl;
}
template <typename T, typename T0, typename T1>	// 3変数
void write(T& x, T0& y, T1& z) {
    cout << x << " " << y << " " << z << endl;
}
template <typename T, typename T0, typename T1, typename T2>	// 4変数
void write(T& x, T0& y, T1& z, T2& w) {
    cout << x << " " << y << " " << z << " " << w << endl;
}
// vectorの出力
template <typename T>
void printvec(const vector<T> &data) {
for (const auto elm : data) {
    cout << elm << " ";
}
cout << endl;
}


int main(int argc, char const *argv[])
{
    vint ls{1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k; read(k); k--;
    cout << ls[k] << endl;
    
    return 0;
}