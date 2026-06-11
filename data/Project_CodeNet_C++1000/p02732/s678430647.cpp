#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    vector<long long>c(n + 1,0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        c[a[i]]++;
    }
    long long sum = 0;
    for(int i = 0;i < n + 1;i++){
        sum += c[i] * (c[i] - 1)/2;
    }
    for(int i = 0;i < n;i++){
        long long  pat;
        pat = sum - (c[a[i]] - 1);
        cout << pat << endl;
    }
}


