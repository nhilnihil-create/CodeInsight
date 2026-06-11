#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N-1);

    for(int i = 0; i < N-1 ; i++){
        cin >> B.at(i);
    }

    A.at(0) = B.at(0);
    for(int i = 0; i < N-1; i++){
        if(B.at(i) < A.at(i)){
            A.at(i) = B.at(i);
            A.at(i+1) = B.at(i);
        }else{
            A.at(i+1) = B.at(i);
        }
    }

    long long ans = 0;
    for(int num : A){
        ans += num;
    }

    cout << ans << endl;
}