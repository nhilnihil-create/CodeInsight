#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15

int main(){

 int r,c,n;

 cin>>r>>c>>n;

 int maxi,mini;
 if(r>c){ maxi = r; mini = c;}
 else if(c>r) {maxi = c; mini = r;}

 int cnt=0,ans=0;

 while(cnt<n){
   cnt += maxi;
   ans++;
 }

  cout<<ans<<endl;

return 0;
 }
