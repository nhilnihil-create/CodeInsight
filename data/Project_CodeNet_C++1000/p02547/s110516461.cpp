#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(2));
    for(int i = 0; i < N; i++){
        cin >> A.at(i).at(0) >> A.at(i).at(1); 
    }
    bool ans = 0;
    for(int i = 0; i < N - 2; i++){
        if(A.at(i).at(0) == A.at(i).at(1) && A.at(i + 1).at(0) == A.at(i + 1).at(1) && A.at(i + 2).at(0) == A.at(i + 2).at(1)){
            ans = 1;
            break;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}