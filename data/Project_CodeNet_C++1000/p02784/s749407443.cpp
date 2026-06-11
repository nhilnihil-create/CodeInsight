#include<bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    int a;
    cin >> N >> K;
    int sum = 0;
    for (int i=0; i<K; i++) {
        cin >> a;
        sum += a;
    }
    sum >= N ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
