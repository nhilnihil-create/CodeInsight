#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main(void){
    // Your code here!
 ll i,k,n,q,s,x;
 s=0;
 cin >> n >> k >> q;
 vector<ll> v(n,0);
 while(q--)
 {
  cin >> x;
  v[x-1]++;
 }
 for(auto it:v)
 s+=it;
 for(i=0;i<n;i++)
 {
  v[i]-=s;
  v[i]+=k;
 }
 for(auto it:v)
 cout << (it>0 ? "Yes" : "No") << '\n';
 return 0;
}