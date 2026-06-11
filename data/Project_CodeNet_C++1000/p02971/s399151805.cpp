#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    int num = 0;
    for(int i = 0; i < N; i++){
        cin >> num;
        A.at(i) = num;
        B.at(i) = num;
    }

    sort(B.begin(), B.end());

    for(int Anum : A){
        if(Anum < B.at(N-1)){
            cout << B.at(N-1) << endl;
        }else{
            cout << B.at(N-2) << endl;
        }
    }
}