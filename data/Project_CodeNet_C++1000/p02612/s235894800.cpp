#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < (N); i++)  

int main()
{
    // 入力
    int N;
    int max,result=0;
    cin >> N;

    //cout << "" << endl;
    // 計算
    if (N%1000>0){
        result = 1000-N%1000;
    }else{
        result = 0;
    }

    // 出力
    cout << result << endl;
    return 0;  
}
