#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> l(n);
    for(int i=0; i<n; ++i){cin >> l[i];}
    sort(l.begin(), l.end());
  	
    int res = 0; int cnt = 0;
    for(int i=0; i<n-2; ++i){
        int a = l[i];
        for(int j=i+1; j<n-1; ++j){
            int b = l[j]; 
            for(int k=j+1; k<n; ++k){
              	
                if(l[k]>(a+b)){break;}
              	if(l[k]==(a+b)){continue;}
                int c = l[k]; 
                if(a<(b+c) && b<c+a){res++;}
            }
        }
    }
    cout << res << endl;
    return 0;
}