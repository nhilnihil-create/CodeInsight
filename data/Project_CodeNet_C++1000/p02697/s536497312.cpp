#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n % 2 == 1){
        for(int i=0; i<m; i++){
            cout << i+1 << " " << n-i << endl;
        }
    }
    if(n % 2 == 0){
        for(int i=0; i<m; i++){
            if(i < n/4) cout << i+1 << " " << n-i << endl;
            else cout << i+2 << " " << n-i << endl;
        }
    }
    return 0;
}