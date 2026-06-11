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


  long long n,d = INT_MIN;
  cin>>n;

  for(long long i=1;i<=sqrt(n);i++)
 {
    if(n%i == 0){
        if(i>d)
            d = i;
    }
  }

  long long b = n/d;

  cout<<b-1+d-1<<endl;

 return 0;
 }
