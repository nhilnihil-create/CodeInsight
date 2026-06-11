////////////////////////////////////
///     Please Give Me AC!!!     ///
////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N;
    cin>> N;
    vector<int> A(N);
    forin(A);
    sort(A.rbegin(), A.rend());

    ll ans = A[0];
    for(int i = 2; i < N; i++) ans += A[i/2];

    cout<< ans << endl;
}