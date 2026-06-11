#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    if(N%2==0) cout << N/2 << endl;
    else cout << N/2 +1 << endl;
}