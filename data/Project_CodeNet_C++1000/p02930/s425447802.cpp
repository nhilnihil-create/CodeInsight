#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> node(n);
    for (int i = 0; i < n; i++) node[i] = i;
    int k = 1;
    while (pow(2, k) < n) k = k << 1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int p = 0; p < k; p++){
                if (((i >> p) & 1) != ((j >> p) & 1)){
                    cout << p + 1;
                    break;
                }
            }
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
}