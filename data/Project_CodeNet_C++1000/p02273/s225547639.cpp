#include <bits/stdc++.h>
using namespace std;

int n;

void solve(double x1, double x2, double y1, double y2, int cnt){ //2点で結ばれた線分をn回分割する。
    if(cnt == n) return; //n回目終わったので終了
    double nx1, nx2, ny1, ny2; //線分上の新たな点の座標
    nx1 = (2 * x1 + x2) / 3; ny1 = (2 * y1 + y2) / 3;
    nx2 = (2 * x2 + x1) / 3; ny2 = (2 * y2 + y1) / 3;
    double mx = (x1+x2)/2 + (-1)*(y2-y1)*sqrt(3)/6, my = (y1+y2)/2 + (x2-x1)*sqrt(3)/6; //出っ張りはベクトルの足し算
    // カウンターを1増やしてに放り込む
    //
    solve(x1, nx1, y1, ny1, cnt + 1);
    cout << fixed << setprecision(8) << nx1 << " " << ny1 << endl;
    solve(nx1, mx, ny1, my, cnt + 1);
    cout << fixed << setprecision(8) << mx << " " << my << endl;
    solve(mx, nx2, my, ny2, cnt + 1);
    cout << fixed << setprecision(8) << nx2 << " " << ny2 << endl;
    solve(nx2, x2, ny2, y2, cnt + 1);
}

int main(){
    cin >> n;
    cout << fixed << setprecision(8) << 0.0 << " " << 0.0 << endl;
    solve(0, 100, 0, 0, 0);
    cout << fixed << setprecision(8) << 100.0 << " " << 0.0 << endl;
    return 0;
}
