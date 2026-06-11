#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
 int h,a;
 cin>>h>>a;
 int ans=0;
 while(h>0){
  h = h - a;
  ans++;
 }
 cout<<ans<<endl;
return 0;
}
