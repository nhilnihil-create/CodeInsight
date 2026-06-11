#include <bits/stdc++.h>
using namespace std;


void solve(long long S, long long W){
    string status;
    if(S > W) status = "safe";
    else status = "unsafe";
    cout << status << endl;
    return;
}

int main(){
    long long S;
    scanf("%lld",&S);
    long long W;
    scanf("%lld",&W);
    solve(S, W);
    return 0;
}
