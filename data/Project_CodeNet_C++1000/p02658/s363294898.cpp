#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long mult=1;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
        if(A.at(i)==0){
            mult=0;
            break;
        }
    }
    if(mult!=0){
        for(int i=0; i<N; i++){
        if(A.at(i)<=(1000000000000000000/mult)) mult=mult*A.at(i);
        else{
            mult=-1;
            break;
        }
        }
    }
    cout << mult << endl;
}