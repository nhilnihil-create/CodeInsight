#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   int m,d;
   cin >>  m >> d;
   int ans=0;
   for(int i=1;i<=m;i++){
       for(int j=1;j<=d;j++){
           int x=j/10;
           int y=j%10;
            if(x>=2 && y>=2 && x*y==i)ans++;
               
       }
   }
   cout << ans << endl;
}



    
   
