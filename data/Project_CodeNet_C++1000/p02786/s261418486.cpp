/*
* ID: juryc
* PROG: Caracal vs monster
* LANG: C++
*/
long long recur(long long h){
if(h==1) return 1;
return 1+2*recur(h/2); 
}
#include<bits/stdc++.h>
using namespace std;
int main(){
long long h; cin>>h;
cout<<recur(h)<<"\n";
return 0;
}