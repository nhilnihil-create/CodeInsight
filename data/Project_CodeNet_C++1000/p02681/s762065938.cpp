#include<bits/stdc++.h>

using namespace std;

int main(){
    string S,T,ans = "No";
    cin >> S >> T;
    if(T==S+T.substr(S.size(),1))ans = "Yes";
    cout << ans << endl;
}