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

    int x = as[N - 1], y;
    for(;idx < N - 1; idx++){
        if(as[idx] < 0) break;
        
        y = as[idx];
        cout << x << " " << y << endl;
        x = x - y;
    }

    y = x;
    x = as[0];
    cout << x << " " << y << endl;
    x = x - y;

    for(;idx < N - 1; idx++){
        y = as[idx];
        cout << x << " " << y << endl;
        x = x - y; 
    }
    return 0;
}