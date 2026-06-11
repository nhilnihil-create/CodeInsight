#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, M;
    cin >> N >> M;
    cout << N * (N-1) / 2 + M * (M-1) / 2 << endl;

    return 0;
}
