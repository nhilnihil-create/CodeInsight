/*
      author : Nishikawa
      created: 07.08.2020 21:15:51
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int K;
    cin >> K;
    string S;
    cin >> S;
    if((int)S.size()<=K){
        cout << S << endl;
        return 0;
    }      
    S.erase(S.begin()+K,S.end());
    string dots("...");
    S=S+dots;
    cout << S << endl;
    return 0;
}