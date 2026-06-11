#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    if(S.size()%2==1){
        cout << "No" << endl;
        return 0;
    }
    int H=0;
    for(int i=0; i<S.size(); i=i+2){
        if(S[i]=='h') H++;
    }
    int I=0;
    if(S.size()/2==H){
        for(int i=1; i<S.size(); i=i+2){
            if(S[i]=='i') I++;
        }
        if(S.size()/2==I) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
    return 0;
    
}