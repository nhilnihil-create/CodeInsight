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

 long long n,c=0,ans=0;
 cin>>n;

  int v[n];

 for(int i=0;i<n;i++){
   cin>>v[i];
    }

    for(int i=1;i<n;i++){

        if(v[i] <=v[i-1])
            ++c;
        else
            c = 0;

      ans = max(ans,c);
    }

  cout<<ans<<endl;

 return 0;
 }
