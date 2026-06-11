


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define inf    0x3f3f3f3f
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef vector<int>      vi;
typedef vector<bool>     vb;
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

  int main(){

   int n; cin>>n;
   string s; cin>>s;

   ll r=0,cnt=0;

   for(int i=0;i<n;i++){
      if(s[i] == 'R')
            r++;
   }

   for(int j=0;j<r;j++){
      if(s[j] == 'W')
      cnt++; }

    cout<<cnt<<endl;

  return 0;
  }