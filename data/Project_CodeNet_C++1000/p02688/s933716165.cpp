#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<int> d(k);
    vector<int> t(n, 0);
    for(int i=0; i<k; ++i){
        cin >> d[i]; d[i]--; 
        for(int j=0; j<=d[i]; ++j){
            int a;
            cin >> a; a--; t[a]++;  
        }
    }
    int res = 0; 
    for(int i=0; i<n; ++i){
        if(t[i]==0){res++;}
    }
    cout << res << endl;
    return 0;
}