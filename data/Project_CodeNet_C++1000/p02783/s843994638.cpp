#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int H, A;
    cin >> H >> A;
    if(H%A==0) cout << H/A << endl;
    else cout << H/A + 1 << endl;
}