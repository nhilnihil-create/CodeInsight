#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, D;
    cin >> N >> D;
    vector<vector<int>> Xij(N, vector<int>(D));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<D; j++){
            cin >> Xij[i][j];
        }
    }

    int count =0;
    double length;
    for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
        length = 0;
        for(int k=0; k<D; k++){
            length += pow((Xij[i][k]-Xij[j][k]),2);
        }
        long long length_int = (long long)round(sqrt(length));
        if( abs(length_int*length_int - length) < 0.00000001){
            count += 1;
        }
    }
    }

    cout << count << endl;
    return 0;
} 