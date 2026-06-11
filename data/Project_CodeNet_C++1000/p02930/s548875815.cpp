#include <bits/stdc++.h>
using namespace std;

int a[500][500];

void calc(int l, int r, int lv){
    if(l < r-1){
        int m = (l+r)/2;
        for(int i=l; i<m; i++)
        for(int j=m; j<r; j++)
            a[i][j] = lv;
        calc(l, m, lv+1);
        calc(m, r, lv+1);
    }
}

int main(){
    int n;
    cin >> n;
    calc(0, n, 1);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}