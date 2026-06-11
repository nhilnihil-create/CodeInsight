#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 1;
int n, m, k;
long long int cs[N]; 
int main(){
    int n, m;
    cin >> n >> m;
    cout << n * (n - 1) / 2 + m * (m - 1) / 2 << endl;
    return 0;
}