#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; ++i) cin >> a[i];
    int cnt=0;
    for (int i=0; i<=N/2; ++i){
        if (a[2*i]%2 == 1) ++cnt;
    }
    cout << cnt;
    return 0;
}