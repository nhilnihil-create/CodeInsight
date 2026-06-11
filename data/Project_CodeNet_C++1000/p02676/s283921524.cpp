#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int K;
    string S;
    cin>>K;
    cin>>S;
    if(S.length()<=K) cout<<S<<"\n";
    else {
        cout<<S.substr(0,K)+"..."<<"\n";
    }
}