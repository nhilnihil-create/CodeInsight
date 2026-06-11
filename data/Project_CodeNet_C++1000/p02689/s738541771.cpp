


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

//int a[100005];


 int main(){

  long long n,m;
  cin>>n>>m;
  int a[n];
  map<int,int>mp;

  for(int i=0;i<n;i++){
    cin>>a[i];
     mp[i] = 1;
  }

 for(int i=0;i<m;i++)
 {
    long long tmp,tmp1;
    cin>>tmp>>tmp1;

    tmp--; tmp1--;

    if(a[tmp] <= a[tmp1]){
        mp[tmp] = 0;
    }

    if(a[tmp1] <= a[tmp]){
        mp[tmp1] = 0;
    }

 }

 long long cnt=0;

 for(int i=0;i<n;i++){
     // cout<<mp[i]<<endl;
    if(mp[i] == 1)
        cnt++;
 }

  cout<<cnt<<endl;

 return 0;
 }
