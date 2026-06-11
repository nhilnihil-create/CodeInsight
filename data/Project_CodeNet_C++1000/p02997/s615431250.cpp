#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int kmax = (n-1)*(n-2)/2;
    if(k > kmax){
        cout << -1 << endl;
        return 0;
    }

    cout << (n-1) + (kmax-k) << endl;
    for(int i=2; i<=n; i++){
        cout << 1 << " " << i << endl;
    }
    int count = 0;
    for(int i=2; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(count == kmax - k) return 0;
            cout << i << " " << j << endl;
            count += 1;
        }
    }
    return 0;
}