#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
string S,T;


ll N,K,M;

int main() {
    cin >> N >> M >> K;
    if(N-K>=0){
        cout << N-K << " " << M << endl;
    }else if(N+M-K>=0){
        cout << 0 << " " << N+M-K << endl;
    }else{
        cout << 0 << " " << 0 <<  endl;
    }
}
