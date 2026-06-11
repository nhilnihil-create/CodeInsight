#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int H, N;
    cin >> H >> N;
    int atk = 0;
    REP(i,N){
        int a;
        cin >> a;
        atk+=a;
    }
    if(atk >= H) cout << "Yes" << endl;
    else cout << "No" << endl;
}