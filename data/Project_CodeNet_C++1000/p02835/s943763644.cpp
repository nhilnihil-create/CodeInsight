#include<bits/stdc++.h>

using namespace std;

int main(){
 #ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("outt.txt", "w", stdout);

#endif
  
   long long mod = 1000000007;


   int a,b,c;
   cin>>a>>b>>c;
   int sum= a+b+c;

   cout<<(sum>=22?"bust":"win");





return 0;
}