#include<bits/stdc++.h>
using namespace std ; 
# define pb push_back
# define ll long long 
# define mp make_pair
# define endl "\n" 
#define pii pair<int,int> 
# define vi vector<int>
# define pll pair<ll,ll> 
# define vl vector<long>

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    ll h , w ; 
    cin >> h >> w ; 
    if(h==1 || w==1) {
    	cout << 1   ; 
    } else {
    	cout << (h*w+1)/2  ;
    }
    return 0; 
}





