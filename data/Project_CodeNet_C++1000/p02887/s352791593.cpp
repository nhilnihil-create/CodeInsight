#include <bits/stdc++.h>
#define ll long long
#define pb puhs_back
#define Int int64_t
using namespace std;

int N;
int main()
{
   cin>>N;
   string S;cin>>S;
   Int ans=1;
   for(int i=1;i<S.length();++i){
       ans+=(S[i]!=S[i-1]);
   }
   cout<<ans<<"\n";
}