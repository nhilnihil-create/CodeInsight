#include <bits/stdc++.h>
using namespace std ;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    if(N%2==0){
        int Ans =0;
        for(int i=0;i<N/2;i++){
            if(S[i]!=S[i+N/2])Ans = 1;
        }
        if(Ans==0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        cout << "No" << endl;
    }
}