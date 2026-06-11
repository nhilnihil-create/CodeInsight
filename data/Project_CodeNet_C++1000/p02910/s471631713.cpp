#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000 
const long long  MOD =1e9+7;
#define MAXR 100000 
int main(){
    string S;
    cin >> S;
    int Ans = -1;
    for(int i=0;i<S.size();i++){
        if(i%2==0){
            if(S[i]=='L')Ans=1;
        }else{
            if(S[i]=='R')Ans=1;
        }
    }
    if(Ans==-1)cout << "Yes" << endl;
    else cout << "No" << endl;
}