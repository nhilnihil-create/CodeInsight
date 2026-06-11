#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){cin >> a[i];}
    bool ok = true;
    for(int i=0; i<n; ++i){
        if(a[i]%2==0){
            if(a[i]%5==0 || a[i]%3==0) continue;
            if((a[i]%3)!=0){ok = false;}
            if((a[i]%5)!=0){ok = false;}
        }
    }
    if(ok){cout << "APPROVED" << endl;}
    else{cout << "DENIED" << endl;}
    return 0;
}