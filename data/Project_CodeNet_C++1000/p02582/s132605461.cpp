#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    int ans=0;
    if(S=="SSS"){
        ans=0;
    }
    else if(S=="SSR" || S=="SRS" || S=="RSS" || S=="RSR"){
        ans=1;
    }
    else if(S=="SRR"|| S=="RRS"){
        ans=2;
    }
    else{
        ans=3;
    }
    cout << ans << endl;
}