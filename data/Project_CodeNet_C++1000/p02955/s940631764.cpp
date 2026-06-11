#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

// assume x is gcd => if unevenness can be vanish within K times operation, OK
// devede +1 part & -1 part

int make_gcd_x( int x, vector<int> &A, int N ){ // A must be sorted
    //now candidate x is devisor of sum(A)
    vector<int> r(N);
    rep(i,N) r[i] = A[i]%x;
    sort(r.begin(),r.end());
    int tot = 0;
    rep(i,N) tot += r[i]; // also multiple of x
    int partation = N - tot/x;
    int step = 0;
    rep( i, partation ) step += r[i];
    return step;
}

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int sum = 0;
    rep(i,N) sum += A[i];
    set<int> devisor; // search all common devisor
    for( int i=1; i*i<=sum; i++ ){ // D = { a<gcd(n) | E(b) s.t. a*b = n } => n(D) <= sqrt(n) 
            if( sum%i==0 ){
            devisor.insert(i);
            devisor.insert(sum/i);
        }
    }
    int ans = 1;
    for( int x : devisor ){
        int step =  make_gcd_x( x, A, N );
        if( step <= K ) ans = max(ans,x);
    }
    cout << ans << endl;
    return 0;
}
