#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;




int main(void){
   int n;
   cin>>n;
   vector<int> a(n),b(n);
   rep(i,n)cin>>a[i];
   rep(i,n)cin>>b[i];
   vector<int> c(n);
   rep(i,n)c[i]=i+1;
   map<vector<int>,int> mp;

   do{
      mp[c]=mp.size();

   }while(next_permutation(c.begin(),c.end()));
int x = abs(mp[a]-mp[b]);
cout<<x<<endl;
return 0;
}


