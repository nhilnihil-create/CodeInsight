#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    int count =0;
    for ( int i=1; i<=N; ++i ){
        int n = to_string(i).length();
        if( n%2 == 1 ) ++count;
    }
    cout << count << endl;
    return 0;
}