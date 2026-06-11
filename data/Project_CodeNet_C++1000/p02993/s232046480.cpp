#include <bits/stdc++.h>
using namespace std ;
int main(){
    string S;
    cin >> S;
    int Ans =1;
    for(int i=0;i<S.size()-1;i++)if(S[i]==S[i+1])Ans =0;
    if(Ans == 1)cout << "Good" << endl;
    else cout << "Bad" << endl;
}