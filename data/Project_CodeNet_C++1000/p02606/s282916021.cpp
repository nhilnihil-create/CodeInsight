#include <bits/stdc++.h>
using namespace std;

int main(void){
    int l,r,d,one_to_r,one_to_l;
    cin >> l >> r >> d;

    one_to_r = r / d;
    one_to_l = (l - 1) / d;

    cout << one_to_r - one_to_l << endl;
    return 0;
}
