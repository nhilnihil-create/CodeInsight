#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int k,x;
    cin >> k >> x;
    rep(i,2*k-1){
        cout << x-k+1+i << endl;
    }
    

    return 0;
}