#include <bits/stdc++.h>
using namespace std;

const long long M = 7 + (long long) 1e9;
const long long DM = 100002;

int main(){
    string S;
    cin >> S;

    long long ans[DM][2]={}; // # digit, smaller flag,
    ans[0][0]=1; ans[0][1]=0; 
    int smaller,bit;
    int N = (int) S.size();


    for(int i=1; i<=N; i++){
        bit = (int) ( S[i-1] - '0' );

        ans[i][0] = ( (bit+1) * ans[i-1][0] )%M; // # doubled only if bit == 1
        ans[i][1] = ( (ans[i-1][1]*3)%M  + bit*ans[i-1][0] )%M; // # if S[i] == 1; new smaller cases        

    }

    cout << ( ans[N][0] + ans[N][1] )%M << endl;

    return 0;
}