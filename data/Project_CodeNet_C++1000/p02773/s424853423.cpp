

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
 map<string,int>s;
 vector<string>b(n);

 for(int i=0;i<n;i++){
    string a;
    cin>>a;
    b[i] = a;
    s[a]++;
 }

 int maxim = 0;

 for(auto p:s){
    auto k = p.first;
    auto v = p.second;
    if(maxim < v)
        maxim = v;
 }

 for(auto p:s){
  auto k = p.first;
  auto v = p.second;

  if(v == maxim) cout<<k<<endl;

 }

  return 0;
 }