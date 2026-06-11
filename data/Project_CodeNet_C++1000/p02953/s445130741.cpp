#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
   int n;
   cin >> n;
   int h[n];
   rep(i,n) cin >> h[i];
   int now = h[n-1],flag= 1;
   for(int i=n-1;0<=i;i--){
       if(h[i]<=now){
           now = h[i];
           continue;
       }
       else if(h[i]==now+1){
            now = h[i]-1;
            continue;
       }
       else flag = 0;
   }
   if(flag) cout << "Yes" << endl;
   else cout << "No " << endl;
}
