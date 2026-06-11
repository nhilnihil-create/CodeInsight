#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int tmp_A_min = (int)round((A-1) / 0.08);
    int tmp_A_max = (int)round((A+1) / 0.08);
    int tmp_B_min = (int)round((B-1) / 0.1);
    int tmp_B_max = (int)round((B+1) / 0.1);

    int min_int = min({tmp_A_min, tmp_A_max, tmp_B_min, tmp_B_max});
    int max_int = max({tmp_A_min, tmp_A_max, tmp_B_min, tmp_B_max});

    for(int i=min_int; i<=max_int; i++){
        if((int)(i*0.08)==A && (int)(i*0.1)==B){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;

}