#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    int b1=0,b2;
    string yn = "Yes";
    rep(i,N){
        b1 = max(b1,b2);
        cin >> b2;
        if( b2 - b1 < -1 ) yn = "No";
    }
    cout << yn << endl;
    return 0;
}
