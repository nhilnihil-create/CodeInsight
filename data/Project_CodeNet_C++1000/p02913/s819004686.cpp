#include <bits/stdc++.h>
using namespace std;

vector<int> Zalgorithm( string S, int N ){
    vector<int> Z(N);
    Z[0] = N;
    int i = 1, j = 0;
    while(i < N){
        while(i + j < N && S[j] == S[i + j]) j++;
        Z[i] = j;

        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(k < j && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
}


int main (){
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int len = 0;
    int n = N;
    for ( int i = 0; i < N-1; ++i){
        //cout << S << endl;
        vector<int> Z;
        Z = Zalgorithm(S,n);
        
        for ( int i = 0; i < n; ++i){
            Z[i] = min(i,Z[i]);
        }
        int m = *max_element(Z.begin(),Z.end());
        len = max(len,m);
        //cout << max << endl;
        
        S.erase(0,1);
        --n;
    }
    
    cout << len << endl;
    return 0;
}

