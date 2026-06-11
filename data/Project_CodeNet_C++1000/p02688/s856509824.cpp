#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    int d = 0;
    int A_okashi = 0;
    for(int i = 0; i < K; i++){
        cin >> d;
        for(int j = 0; j < d; j++){
            cin >> A_okashi;
            A.at(A_okashi-1)++;
        } 
    }

    int count = 0;
    for(int num : A){
        if(num == 0){
            count++;
        }
    }

    cout << count << endl;
}