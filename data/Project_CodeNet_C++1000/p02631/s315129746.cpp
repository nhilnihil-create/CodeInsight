/*
      author : Nishikawa
      created: 06.08.2020 17:46:44
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int N;
    cin >> N;//偶数
    vector<ll> a(N,0);
    for(int i=0; i<N; i++) cin >> a[i];
    ll X=a[0];
    for(int i=1; i<N; i++)
        X=X^a[i];
    for(int i=0; i<N; i++){
        ll tmp = X^a[i];
        cout << tmp << endl;
    }
    return 0;
}