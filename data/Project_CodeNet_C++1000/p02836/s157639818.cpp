#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Int int64_t
using namespace std;

Int N;

int main()
{
   string S;cin>>S;
   int i=0,j=S.length()-1;
   Int ans=0;
   while(i<=j){
       ans+=S[i]!=S[j];
       i++,j--;
   }
   cout<<ans<<"\n";
}