


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

#define access(i) a[i/3][i%3]
int gcd(int x, int y)
{
    if(y==0)
        return x;
    return gcd(y, x%y);
}

 long long numbers[500005];

  int main(){

 ll x;
  cin>>x;

   for(ll i=-1000;i<=1000;i++){
    for(ll j=-1000;j<=1000;j++){
        if(i*i*i*i*i-j*j*j*j*j == x){
            cout<<i<<" "<<j<<endl;
             return 0; }
    }
   }


  return 0;
  }