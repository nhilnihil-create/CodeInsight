#include<bits/stdc++.h>

#define I first
#define prob ' '
#define II second
#define pb push_back
#define tm (tl+tr)/2

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;

void solve(ll rem_tests){
    if (!rem_tests) return;
    ll k;
    cin >> k;
    while(k--) cout << "ACL";
    solve(rem_tests-1);
}
int main(){
    ll N_of_tests = 1;
    //cin >> N_of_tests;
    solve(N_of_tests);
   return 0;
}
