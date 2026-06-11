#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string S, T;
    cin >> S >> T;

    if(S.size()+1==T.size()){
        int flag=0;
        rep(i, S.size()){
            if(S[i]!=T[i]) flag=1; 
        }
        if(flag==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else cout << "No" << endl;

    return 0;
}