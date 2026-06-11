#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string S,T;
    cin >> S;
    cin >> T;
    int count = 0;
    rep(i,S.size()){
        if( S[i] != T[i] ) ++count;
    }
    cout << count << endl;
    return 0;
}