#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string S;
    cin>>S;
    int cnt = S.length();
    // cout<<cnt<<endl;
    if(S.at(cnt-1)=='s'){
        S = S+ "es";
    }
    else{
        S = S + "s";
    }
    cout<<S<<endl;
}