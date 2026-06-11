#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> p;

int main(){
    int n; cin >> n;
    vector<ll> h(n);
    for(int i=0; i<n; ++i){cin >> h[i];}
    reverse(h.begin(), h.end());
    for(int i=0; i+1<n; ++i){
        if(h[i+1]<0){cout << "No" << endl; return 0;}
        if(h[i+1]>h[i]){h[i+1]--;}
    }
   //for(int i=0; i<n; ++i){cout << h[i] << ",";} cout << endl;
  	for(int i=0; i+1<n; ++i){if(h[i+1]>h[i]){cout << "No" << endl; return 0;}}
    cout << "Yes" << endl; return 0;
    return 0;
}