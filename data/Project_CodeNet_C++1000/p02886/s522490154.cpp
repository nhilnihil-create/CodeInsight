#include<iostream>
#include<bitset>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec[i];
    int sum = 0;
    rep(i,n)
        for(int j = i + 1; j < n; j++)
            sum += vec[i] * vec[j];
    
    cout << sum << endl;
}