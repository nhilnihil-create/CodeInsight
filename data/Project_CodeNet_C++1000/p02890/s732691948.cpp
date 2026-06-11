#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
     cin >> n;
     vector<int> a(n);
     vector<int> appear(n + 1, 0);
     vector<int> appear2(n + 1, 0);
     vector<int> prefixSumK(n + 1, 0), prefixSum(n + 1, 0);
     vector<int> f(n + 1);
    for(int i = 0; i< n;i++){
        cin >> a[i];
        appear[a[i]] ++;
    }
    for(int i = 1; i <= n;i ++){
        int ci = appear[i];
        appear2[ci] ++;
    }
    for(int i = 1; i <= n; i++){
        prefixSumK[i] = prefixSumK[i-1] + i * appear2[i];
        prefixSum[i] = prefixSum[i-1] + appear2[i];
    }
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        f[i] = (prefixSumK[i] + i * (prefixSum[n] - prefixSum[i])) / i;
    }

    int ptr = n;
    for(int k = 1; k <= n; k++){
        while(ptr > 0 && f[ptr] < k){
            ptr --;
        }
        cout << ptr << "\n";
    }
}
