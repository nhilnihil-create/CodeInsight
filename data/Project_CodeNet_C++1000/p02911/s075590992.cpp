#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long N, K, Q;
    cin >> N >> K >> Q;

    long long A[Q];
    for(int i=0; i<Q; i++){
        cin >> A[i];
    }

    vector<long long> Point(N, 0);
    
    for(int i=0; i<Q; i++){
        Point[A[i]-1] += 1;
    }

    for(int j=0; j<N; j++){
        if(Q - Point[j] < K){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

    return 0;
}