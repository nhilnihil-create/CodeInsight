
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

long long n,cnt=0;
 cin>>n;

 string s;
 cin>>s;

 int len = s.length();
  char prev = '$';

  for(int i=0;i<len;i++)
  {
     if(s[i] != prev)
     {
         prev = s[i];
         cnt++;
     }
  }

  cout<<cnt<<endl;

  return 0;
 }