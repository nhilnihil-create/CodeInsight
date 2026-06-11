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
    bool can = true;
    REP(i,N){
        int a;
        cin >> a;
        if(a%2==0){
            if(a%3!=0 && a%5!=0) can = false;
        }
    }
    if(can) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
}