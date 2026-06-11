#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define uset unordered_set<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a;
    cin >> n;
    uset x;
    
    for(ll i=0; i<n; i++){
        cin >> a;
        x.insert(a);
    }
    
    if(x.size() != n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}