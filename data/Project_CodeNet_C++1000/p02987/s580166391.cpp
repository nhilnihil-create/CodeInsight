                                       //BISMILLAHIR RAHMANIR RAHIM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define     ll          long long 
#define     MP          make_pair
#define     MT          make_tuple 
#define     endl        '\n'
#define     iscanf(a)   scanf("%d",&a)
#define     llscanf(a)  scanf("%lld",&a)
#define     flp(n)      for(i=0;i<n;i++)
#define     inlp(n)     for(i=n-1;i>=0;i--)
#define     PB          push_back
#define     IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     inout       freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define     mset(arr,n) memset(arr,n,sizeof(arr))
#define     vci         vector<int>
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}

int main(){
int arr[27];
mset(arr,0);
string s;

cin>>s;
for(int i=0;i<4;i++)arr[s[i]-'A']++;
  int tot=0;
for(int i=0;i<27;i++)if(arr[i]==2)tot++;
  if(tot==2)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;

}