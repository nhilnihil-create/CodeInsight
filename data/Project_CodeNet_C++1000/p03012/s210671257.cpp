#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    vector<int> W(N);
    for(int i = 0; i < N; i++){
        cin >> W[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < N; i++){
        // S1とS2の合計値の宣言
        int s1_Sum = 0;
        int s2_Sum = 0;
        // S1とS2のエリアの合計値を求める
        for(int s1 = 0; s1 <= i; s1++) s1_Sum += W[s1];
        for(int s2 = i+1; s2 < N; s2++) s2_Sum += W[s2];
        //cout << s1_Sum << " " << s2_Sum << endl;
        ans = min(ans, abs(s1_Sum - s2_Sum));
    }
    
    cout << ans << endl;
}
