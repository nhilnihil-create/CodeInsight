#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k ;
    vector<int> a(n);
    for(int i=0; i<n; ++i){cin >> a[i];}
    
    int l = 0; int r = 1000100010; 
    while(r-l>1){
        int mid = (r+l)/2;
        int cut = 0;
        for(int i=0; i<n; ++i){
            if(a[i]==mid){continue;}
            cut += (a[i]/mid); 
        }
        if(cut<=k){r = mid;}
        else{l = mid;}
    }
    cout << r << endl;
    return 0;
}