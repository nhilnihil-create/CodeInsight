#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    vector<int> tmp = A;
    sort(tmp.begin()+1, tmp.end(), greater<int>());
    for(int i = 1; i <= N; ++i){
        if(tmp[1] == A[i]) cout << tmp[2] << endl;
        else cout << tmp[1] << endl;
    }
    return 0;
}