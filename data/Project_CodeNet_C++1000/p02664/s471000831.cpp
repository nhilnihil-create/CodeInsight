#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    for(int i=S.length()-1; i>=0; i--){
        if(S.at(i)=='?') S.at(i)='D';
    }
    cout << S << endl;
    return 0;
}