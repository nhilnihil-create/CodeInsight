#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i);
    }

    long long sum = 1000000000;
    for(int i = 1; i <= 100; i++){
        long long cost = 0;
        for(int j = 0; j < N; j++){
            cost += (X.at(j) - i) * (X.at(j)-i);
        }
        sum = min(sum, cost);
    }

    cout << sum << endl;
}