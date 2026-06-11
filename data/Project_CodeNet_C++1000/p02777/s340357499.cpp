#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, T, U;
    pair<int, int> num;
    cin >> S >> T;
    cin >> num.first >> num.second;
    cin >> U;
    if (U == S){
        cout << num.first - 1  << " " << num.second << endl;
    }
    else{
        cout << num.first << " " << num.second - 1 << endl;
    }
}