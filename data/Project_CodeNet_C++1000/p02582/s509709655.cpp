#include<bits/stdc++.h>
using namespace std;
string S;
int main(){
    cin >> S;
    if(S == "RSR" || S == "RSS" || S=="SSR" || S == "SRS"){cout<<1;return 0;}
    else if(S == "SSS"){cout<<0;return 0;}
    else if(S == "SRR" || S == "RRS"){cout<<2;return 0;}
    else{
        cout<<3;return 0;
    }

}
