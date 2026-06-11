#include <bits/stdc++.h>
using namespace std;

int main(){
    int K,N; cin >> K >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int longest=0;
    for(int i=0; i<N-1; i++){
        longest=max(longest,(A.at(i+1)-A.at(i)));
    }
    longest=max(longest,(A.at(0)+K-A.at(N-1)));
    cout << K-longest << endl;
}