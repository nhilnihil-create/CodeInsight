#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll k,x;cin >>k>>x;
    for (int i = -k+1; i <k; ++i) {
        cout <<x+i<<" ";
    }
    cout <<endl;
    return 0;
}

