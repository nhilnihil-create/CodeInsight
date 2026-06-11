#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;

    // レベルの同じ経路に着目すれば二分グラフが構成できる
    // 2^k 個の部屋は k 個の二分グラフに分けられることがわかるので、
    // bit 演算を用いてどの二分グラフに属するかを判別する
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            for(int k = 0; k < N; ++k){ 
                if((i^j) & (1 << k)){
                    cout << k+1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}