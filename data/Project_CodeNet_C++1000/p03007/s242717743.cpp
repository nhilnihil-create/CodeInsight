#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0,tmpf,tmpb;
    cin >> N;
    vector<long long int> A(N);
    vector<pair<long long int,long long int>> P;

    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    tmpf = A[0];
    tmpb = A.back();

    for(int i=1;i<N-1;i++){
        if(0<=A[i]){
            P.push_back({tmpf,A[i]});
            tmpf -= A[i];
        }else{
            P.push_back({tmpb,A[i]});
            tmpb -= A[i];
        }
    }

    P.push_back({tmpb,tmpf});

    cout << tmpb - tmpf << endl;

    for(int i=0;i<N-1;i++){
        cout << P[i].first << " " << P[i].second << endl;
    }
}