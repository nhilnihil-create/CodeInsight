#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main () {

    double a, b, C;     // 入力

    double c;           // 角Cの対角に存在する辺cの長さ
    double sinB;        // bの対角に存在する角Bのsin
    
    double S, L, h;     // 出力（面積, 周の長さ, ）

    cin >> a >> b >> C;

    C = C * M_PI / 180.0;   // 角度Cをラジアンに変換
    c = sqrt (pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C));  // Cの対角に存在する辺cの長さを求める。余弦定理を利用。 「c^2 = a^2 + b^2 - 2ab * cos(C)」
    sinB = b * sin(C) / c;  // sinAを求める。正弦定理を利用。　「a / sin(A) = b / sin (B) = c / sin (C) = 2R」

    S = 0.5 * a * b * sin(C);   // 面積を求める。面積を求める公式を利用。
    
    L = a + b + c;  // 周の長さを求める。

    h = c * sinB; // 高さを求める。

    cout << fixed;
    cout << setprecision(10) << S << endl;
    cout << setprecision(10) << L << endl;
    cout<< setprecision(10) << h << endl;

    return 0;
}
