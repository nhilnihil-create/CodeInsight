

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

 long long x,N;
 cin>>N;
 vector<int>B(N);
  B[N-1] = 100000;

 for(int i=0;i<N-1;i++){
        cin>>x;
   B[i] = x;
 }

 long long ans = B[0];

 for(int i=1;i<N;i++){

 // cout<<B[i]<<"?"<<endl;
   int a = min(B[i],B[i-1]);

   ans += a;
 }

 cout<<ans<<endl;

 return 0;
}
