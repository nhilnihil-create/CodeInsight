#include "bits/stdc++.h"
 
using namespace std;
 
using ll = long long;
 
#define all(x) begin(x), end(x)
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); 

map<int, int> yes;
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
int n; cin >> n;
vector<int> arr(n);
for(int i{}; i<n; i++){
	int x; cin >> x;
	arr[i] = x;
	++yes[x];
}

 ll tp = 0;
    for(auto x : yes){
        if(x.second)
            tp += 1.0*x.second*(x.second-1)/2;
    }


    for(int i{}; i<n; i++){
    	ll p = 1.0*(yes[arr[i]])*(yes[arr[i]]-1)/2;
    	ll nw = 1.0*(yes[arr[i]]-1)*(yes[arr[i]]-2)/2;
    	cout << tp - p + nw << "\n";
    }









 
}