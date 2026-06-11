#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int m = 0;
    vector<int> b(n+1, 0);
    for(int i = n; i >= 1; i--){
        int cnt = 0;
        int j = 2*i;
        for(int k = 3; j <= n; k++){
            cnt += b[j];
            j = i*k;
        }
        cnt %= 2;
        b[i] = cnt ^ a[i];
        if(b[i]) m++;
    }

    cout << m << endl;
    for(int i = 1; i <= n; i++){
        if(b[i] == 1) cout << i << ' ';
    }
}