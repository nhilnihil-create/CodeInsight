#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int A, B, K;
    cin >> K >> A >> B;

    if(B%K <= B-A) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}