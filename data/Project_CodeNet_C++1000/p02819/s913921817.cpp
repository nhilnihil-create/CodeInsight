/* 
* ID: juryc
* PROG: Next Prime
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int x; cin>>x;
int i=2;
while(true){
int flag=1;
for(int j=2;j*j<=i;j++){ if(i%j==0) flag=0;}
if(flag&&i>=x) { cout<<i<<"\n"; return 0;}
i++; 
}
return 0;
}