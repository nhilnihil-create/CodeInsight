#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000



int main(){

 int n,k,s;
 cin>>n>>k>>s;
   ll inf = 1e10;
    vector <long long> ans(n, inf);

    for(int i=0;i<k;i++){
      ans[i] = s; }

    for(int i=0;i<n;i++){
      if(ans[i] == inf){
              if (s == 1e9) ans[i] = 1;
            else ans[i] = 1e9;
      }
    }

    for(int i=0;i<n;i++)
      cout<<ans[i]<<" ";

    cout<<endl;
    return 0;
}
