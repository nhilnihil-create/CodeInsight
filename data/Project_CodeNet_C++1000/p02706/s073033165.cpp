#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> time(M);
    for(int i = 0; i < M; i++){
        cin >> time.at(i);
    }

    int day = 0;

    for(int i = 0; i < M; i++){
        day += time.at(i);
    }

    if(day <= N){
        cout << N - day << endl;
    }
    else{
        cout << -1 << endl;
    }
}