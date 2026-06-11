#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    if(A.at(N / 2) - A.at(N / 2 -1) > 0){
        cout << A.at(N / 2) - A.at(N / 2 -1) << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}