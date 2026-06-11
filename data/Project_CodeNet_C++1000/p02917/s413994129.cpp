#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> B(N-1);
    
    for(int i = 0; i < N-1; i++){
        cin >> B.at(i);
    }

    long long score = B.at(0);

    for(int i = 0; i < N-2; i++){
        if(B.at(i) < B.at(i+1)){
            score += B.at(i);
        }else{
            score += B.at(i+1);
        }
    }

    score += B.at(N-2);

    cout << score << endl;
}