#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){

    ll n,k,dgt=0; cin >> n >> k;

    while(n!=0){
        n=n/k;
        dgt++;
    }

    cout << dgt << endl;

     return 0;
}