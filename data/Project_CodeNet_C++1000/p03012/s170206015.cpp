#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        int a; cin >> vec.at(i);
    }
    int error = 1000000;
    for(int i = 0; i < n-1 ; i++){
        int sum_1 = 0, sum_2 = 0;
        for(int j = 0; j <= i; j++){
            sum_1 += vec.at(j);
        }
        for(int k = i+1; k < n; k++){
            sum_2 += vec.at(k);
        }
        if(abs(sum_1 - sum_2) < error) error = abs(sum_1 - sum_2);
    }

    cout << error << endl;

    return 0;
}
