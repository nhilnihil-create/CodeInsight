#include <bits/stdc++.h>
using namespace std;;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> fruits(n);
    for (int i = 0; i < n; i++){
        cin >> fruits[i];
    }
    sort(fruits.begin(),fruits.end());
    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += fruits[i];
    }
    cout << sum << endl;
}