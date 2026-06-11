#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 1;
int n, m, k;
long long int cs[N]; 
int main(){
    int n;
    cin >> n;
    long long int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n ; j += i)
            cs[j]++;
        sum += 1LL * i * cs[i];
    }
    cout << sum << endl;
    return 0;
}