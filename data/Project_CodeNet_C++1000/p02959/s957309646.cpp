#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> p;

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n);
    for(int i=0; i<n+1; ++i){cin >> a[i];}
    for(int i=0; i<n; ++i){cin >> b[i];}
    ll res = 0;
    for(int i=0; i<n+1; ++i){res += a[i];} 
    for(int i=0; i<n; ++i){
      	int ai = a[i];
        a[i] -= min(a[i], b[i]);
      	if(b[i]>ai){b[i] -= ai;}else{b[i] = 0;} //cout << b[i] << endl;
      	
        if(b[i]){
            a[i+1] -= min(a[i+1], b[i]);
        }
      	//for(int i=0; i<n+1; ++i){cout << a[i] << ",";} cout << endl;
    }
    for(int i=0; i<n+1; ++i){res -= a[i];}
    cout << res << endl;
    return 0;
}