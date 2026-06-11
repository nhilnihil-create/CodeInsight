#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    int N = S.length();
    // get step to be elgotic in the graph (Ergodic hypothesis)
    vector<int> change(N,0);
    char prev = 'R';
    int count = 0;
    int converge = 0;
    int non_connected = 0;
    rep(i,N){
        if( S[i] == prev ) ++count;
        else{
            converge = max(count,converge);
            count = 1;
            prev = S[i];
            change[non_connected] = i;
            non_connected += 1;
        }
    }
    change.erase( change.begin() + non_connected, change.end() ); // start: R, end: L => len(change) is odd
    cout << endl;
    vector<int> vout(N,0);
    for( int i=0; i<int(change.size()); i+=2 ){
        int prv = 0;
        if( i > 0 ) prv = change[i-1];
        int now = change[i];
        int nxt = N;
        if( i < change.size()-1 ) nxt = change[i+1];
        vout[now-1] = (now -prv)/2 + (nxt -now)/2 + (now -prv)%2;
        vout[now] = (now -prv)/2 + (nxt -now)/2 + (nxt-now)%2;
    }
   for( int n : vout ) cout << n << endl;
    return 0;
}