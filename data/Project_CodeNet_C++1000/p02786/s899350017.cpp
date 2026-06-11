#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;
using namespace std;

int main(){

 long long h;
 cin>>h;

 long long cnt=0;

 while(h>1){
    h /=2;
    cnt++;
 }

 long long ans=0,now=1;

 for(int i=0;i<cnt+1;i++){
    ans += now;
    now *= 2;
 }

 cout<<ans<<endl;

return 0;
}
