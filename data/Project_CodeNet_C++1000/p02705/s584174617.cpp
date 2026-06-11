#include <bits/stdc++.h>
using namespace std;

int main(){
    int R;
    scanf("%d", &R);
    //円周の長さ＝2*半径*円周率
    float ans = 2 * R * 3.14159265359;
    cout << fixed << setprecision(15);
    cout << ans << endl;
}