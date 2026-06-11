

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
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
#define MOD 1000000007

 int main(){

 long long l,r;
 cin>>l>>r;

  if(r-l > 2019){
    cout<<"0"<<endl;
  return 0; }
 else {

   long long ans = 2018;

 for(long long i=l;i<=r;i++)
 {
    for(long long j=i+1;j<=r;j++)
     {
        ans = min(ans,i*j%2019);
    }
 }
    cout<<ans<<endl;
    return 0;
 }


 }
