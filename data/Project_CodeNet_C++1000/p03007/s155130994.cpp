#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    ll t = A[0];
    vector<pair<ll,ll>> ans;
    for(int i=1;i<N;i++){
        if(i==N-1){
            cout << A[i] -t << endl;
            ans.emplace_back(A[i],t);
            break;
        }
        if(A[i] >=0){
            ans.emplace_back(t,A[i]);
            t = (t-A[i]);
        }else{
            ans.emplace_back(A[N-1],A[i]);
            A[N-1] -= A[i];
        }
        
    }
    for(auto P:ans){
        cout << P.first << " "<<P.second<<endl;
    }

    return 0;
}
