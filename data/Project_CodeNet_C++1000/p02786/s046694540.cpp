#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    ll H;
    cin >> H;
    ll atk=0;
    int i = 0;
    while(H>0){
        atk += pow(2,i);
        ++i;
        H/=2;
    }
    cout << atk << endl;
}