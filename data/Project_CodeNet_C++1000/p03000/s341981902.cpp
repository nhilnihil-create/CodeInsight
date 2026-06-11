#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    int n,x;
    cin >> n >> x;
    int l[n];
    for(int i=0; i<n; i++){
        cin >> l[i];
    }

    int c = 0;
    int d[n];
    d[0] = 0;

    for(int i=1; i<n+1; i++){
        d[i] = d[i-1] + l[i-1];
        if(d[i] <= x){
            c++;
        }
    }

    cout << c+1 << endl;
}