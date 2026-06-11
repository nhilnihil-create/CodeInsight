#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> s(m), c(m);
    for(int i=0; i<m; ++i){
        cin >> s[i] >> c[i]; s[i]--;
    }
    for(int i=0; i<1000; ++i){
        vector<int> v;
        v.push_back(i%10); 
        int d = i/10;
        while(d){
            v.push_back(d%10);
            d /= 10;
        }
        if(v.size()!=n){continue;}  

        reverse(v.begin(), v.end()); 
        bool ok = true;
        for(int j=0; j<m; ++j){
            if(v[s[j]]!=c[j]){ok = false;}
        }
      	
        
        if(ok){cout << i << endl; return 0;}
    }
    cout << -1 << endl; return 0;
}