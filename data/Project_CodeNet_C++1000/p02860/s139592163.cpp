#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    string S,ans="No";
    cin >> N >> S;
    if(N%2==0){
        int n = N/2;
        string T = S.substr(0,n);
        if(S==T+T) ans = "Yes";
    }
    cout << ans << endl;
}