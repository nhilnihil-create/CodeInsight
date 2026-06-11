#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                if(A.at(i) == A.at(j) || A.at(i) == A.at(k) || A.at(k) == A.at(j)){
                    continue;
                }
                if(A.at(i) + A.at(j) > A.at(k) && A.at(i) + A.at(k) > A.at(j) && A.at(k) + A.at(j) > A.at(i)){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}