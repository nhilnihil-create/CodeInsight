#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    cin >> N ;
    
    
    // 1の位の数字だけを取り出すときは10で割った余りを求めれば良い
    int ans = N%10 ;
    
    //同じ処理をする条件分岐が複数あるときはswitchを使う
    switch( ans ){
        case 2 :
        case 4 :
        case 5 :
        case 7 :
        case 9 :
            cout << "hon" << endl;
            break;
        case 0 :
        case 1 :
        case 6 :
        case 8 :
            cout << "pon" << endl;
            break;
        case 3 :
            cout << "bon" << endl;
    }
    
}
