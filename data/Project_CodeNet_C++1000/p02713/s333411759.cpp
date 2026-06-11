#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int mm[201][201];

int gcd(int a, int b){
   if(a<b){int tmp=a; a=b; b=tmp;}
   if(mm[a][b] != -1) return mm[a][b];
   int ret;
   if(a%b==0) ret=b;
   else ret=gcd(a%b, b);
   mm[a][b]=ret;
   return ret;
}

int main(){
   int k;
   cin>>k;

   rep(i, 201) rep(j, 201) mm[i][j]=-1;

   ll sum=0;
   for(int i=1; i<=k; i++) for(int j=1; j<=k; j++) for(int l=1; l<=k; l++){
      sum+=gcd(gcd(i, j), l);
   }

   cout << sum << endl;
   return 0;
}
