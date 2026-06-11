#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    int sum=0;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
        sum=sum+A.at(i);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    if(A.at(M-1)*4*M<sum) cout << "No" << endl;
    else cout << "Yes" << endl;
}