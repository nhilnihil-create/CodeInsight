#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int pow2 = 1, d;
    for(int i=1; i<=9; i++){// 500 < 2^9
        pow2 *= 2;
        if(n <= pow2){ d = i; break; }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //cout << i << " " << j << endl;
            for(int k=0; k<d; k++){
                if(((i >> k) & 1) == ((j >> k) & 1)) continue;

                ans[i][j] = k+1;
                break;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            cout << ans[i][j];
            if(j == n-1) break;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}