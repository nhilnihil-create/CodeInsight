#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    int sum=0;
    rep(i, min(S.size(), T.size())){
        if(S[i] != T[i]) sum++;
    }

    cout << sum << endl;
}