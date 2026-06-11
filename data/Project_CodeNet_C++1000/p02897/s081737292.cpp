#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    cout.precision(10);
    cout << (double)(n - n/2) / (double)n << endl; 
    return 0;
}