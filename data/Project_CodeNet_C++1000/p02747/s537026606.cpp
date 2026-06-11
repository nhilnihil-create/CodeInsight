#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){
    
    string S;
    cin >> S;
    if(S.size()%2==1){
        cout << "No" <<endl;
        return 0;
    }
    
    string hi;
    for(int i = 0; i < S.size()/2;i++)hi += "hi";
    
    if(hi == S)cout << "Yes"<<endl;
    else cout << "No" <<endl;
}