#include<bits/stdc++.h>
using namespace std;

int main(){

    int t, i, j, b, h=0;
    cin >> t ;
    int a[t];

    for(i=1; i<=t; i++){
        cin >> a[i] ;
    }
    for(j=1; j<=t; j++){
        if(a[j]!=j){
           h++;
        }
    }
    if(h<=2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    return 0;
}