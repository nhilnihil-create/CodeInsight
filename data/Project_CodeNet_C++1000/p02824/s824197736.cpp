#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M,V,P;
    cin >> N >> M >>V >> P;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    ll sum[N+1] = {};
    for(int i=0;i<N;i++){
        sum[i+1] += sum[i];
        sum[i+1] += A[i];
        if(i < P){
            continue;
        }
        if((i-P+1)*(A[i]+M) < (sum[i]-sum[P-1])+M*max(V-(P-1)-(N-1-i)-1,0LL) || A[i] +M < A[P-1]){
            cerr << "sum=" <<sum[i] -sum[P-1] << endl;
            // cerr <<"i=" <<i <<"A[i]=" << A[i]<< "canNot" << endl;
            cout << i<<endl;
            return 0;
        }

        
    }
    cout << N <<endl;
    return 0;
}