

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

  int n; cin>>n;
  set<int>s;

  for(int i=0;i<n;i++)
 {
     int a;
     cin>>a;
     if(s.count(a)){
        cout<<"NO"<<endl;
        return 0;
        }
      s.insert(a);
  }

  cout<<"YES"<<endl;

 return 0;
 }
