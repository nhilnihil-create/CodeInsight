#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }

    long long val = H[N-1];
    for(int i=N-2; i>=0; i--){
        if(H[i] <= val){
            val = H[i];    
            continue;
        }else{
            if(H[i]-1 <= val){
                val = H[i] - 1;
                continue;
            }
        }

        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;

}