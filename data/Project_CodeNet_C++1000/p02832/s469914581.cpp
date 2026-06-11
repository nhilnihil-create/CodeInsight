#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 1000000;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){cin >> a[i];}
  	bool ok = false;
  	for(int i=0; i<n; ++i){if(a[i]==1){ok = true; break;}}
  	if(!ok){cout << -1 << endl; return 0;}
    int now = 1;
    int res = 0;
    for(int i=0; i<n; ++i){
        if(a[i]!=now){res++;}
      	else{now++;}
    }
    cout << res << endl;
    return 0;
}