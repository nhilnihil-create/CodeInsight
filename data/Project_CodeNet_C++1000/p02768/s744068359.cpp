#include <bits/stdc++.h>
using namespace std;

int64_t kaijo(int64_t P, int64_t C, int64_t div);
int64_t modpow(int64_t a, int64_t dim, int64_t div);

int main(){

    int64_t n, a, b;
    cin >> n >> a >> b;

    int64_t combo_num=0, combo_a=0, combo_b=0, ans=0, div=0;
    int64_t temp_x=0, temp_y=0;

    div = 1e9 + 7;

    //   総組み合わせ数の計算
    combo_num = modpow(2, n, div) - 1;
//    cout << combo_num << endl;

    //  aが含まれる場合の計算
    temp_x = kaijo(n, a, div);
//    cout << "temp_x = " << temp_x << endl;
    temp_y = kaijo(a, a, div);
//    cout << "temp_y = " << temp_y << endl;
    combo_a = ( temp_x*modpow(temp_y, div-2, div) )%div;
//    combo_a = temp_x*modpow(temp_y, div-2, div);
//    cout << "combo_a = " << combo_a << endl;

    //  bが含まれる場合の計算
    temp_x = kaijo(n, b, div);
//    cout << "temp_x = " << temp_x << endl;
    temp_y = kaijo(b, b, div);
//    cout << "temp_y = " << temp_y << endl;
    combo_b = ( temp_x*modpow(temp_y, div-2, div) )%div;
//    combo_b = temp_x*modpow(temp_y, div-2, div);
//    cout << "combo_b = " << combo_b << endl;

    ans = ( combo_num - (combo_a + combo_b)%div + div)%div;

    cout << ans << endl;
    return 0;
}

//  階乗計算
int64_t kaijo(int64_t P, int64_t C, int64_t div){

    if (C == 0){
        return 1%div;
    }
    else{
        return ( P*kaijo(P-1, C-1, div) )%div;
    }
}

//  繰り返し2乗法
int64_t modpow(int64_t a, int64_t dim, int64_t div){

    if (dim == 1){
        return a%div; 
    }
    else if (dim%2 != 0){
        return ( a*modpow(a, dim-1, div) )%div;
    }
    else{
        return ( modpow(a, dim/2, div) * modpow(a, dim/2, div) )%div;
    }
}