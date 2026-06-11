#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; i++) {
        cin>>A[i];
    }
    int temp;
    ll sum = 0;
    int maxN = 0;
    for (int i = 0; i < N; i++) {
        maxN = max(maxN,A[i]);
        temp = maxN;
        sum += temp - A[i];
    }
    cout << sum;
}