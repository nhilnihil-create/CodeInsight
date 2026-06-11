#include<bits/stdc++.h>

using namespace std;

int main(){
    int k, n, i;
    cin >> k >> n;
    int v[n];
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    int aux;
    aux = k - (v[n-1] - v[0]);

    for(i = 1; i < n; i++){
        aux = max(aux,v[i]-v[i-1]);
    }
    cout << k - aux << endl;

    return 0;
}