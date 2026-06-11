#include<bits/stdc++.h>
using namespace std;
int main(){
  while(1){
        int m,n1,n2,ans,max=0,s,p;
        int a[10000];
        cin >> m >> n1 >> n2;
        if(m==0 && n1==0 && n2==0) break;
        for(int i=0; i<m; i++){
          cin >> p;
          a[i] = p;
        }
        for(int i=n1; i<=n2; i++){
          s = a[i-1] - a[i];
          if(s >= max) {
                ans = i;
                max = s;
          }
        }
        cout << ans << endl;
  }
  return 0;
}
