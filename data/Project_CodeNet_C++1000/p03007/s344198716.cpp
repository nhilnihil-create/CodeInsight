#include<bits/stdc++.h>
using namespace std;
int N;
int sum;
vector<int> as;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        as.push_back(A);
        sum += A;
    }
    sort(as.rbegin(), as.rend());

    sum -= 2* as[N - 1];
    for(int i = N - 2; i > 0; i--){
        if(as[i] < 0) sum -= 2 * as[i];
    }

    cout << sum << endl;

    int idx = 1;
    int Y = as[N - 1];
    for(;idx < N - 1; idx++){
        if(as[idx] < 0) break;
        cout << Y << " " << as[idx] << endl;
        Y -= as[idx];
    }

    int X = as[0];
    for(;idx < N - 1; idx++){
        cout << X << " " << as[idx] << endl;
        X -= as[idx]; 
    }
    cout << X << " " << Y << endl;
    return 0;
}