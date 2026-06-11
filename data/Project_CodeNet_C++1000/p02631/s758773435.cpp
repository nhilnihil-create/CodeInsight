#include<iostream>
#include<vector>
using namespace std;
#define MAX 200000

int main() {
    int n;
    vector<int> a(MAX+10);
    int sum = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum ^= a[i];
    }

    for (int i = 0; i < n; i++) cout << (sum ^ a[i]) << ' ';
    cout << endl;
}