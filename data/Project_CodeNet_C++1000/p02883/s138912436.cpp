#include <bits/stdc++.h>
using namespace std;
long long hhhh(vector<long long> a,vector<long long> b,long long c){
  int y = a.size();
  long long d = 0;
  for(int i = 0;i < y;i++){
    long long s = b.at(i);
    long long j = c / a.at(i);
    long long zeroa = 0;
    d += max(s-j,zeroa);
  }
  return d;}

int main() {
  long long n,k;
  cin >> n >> k;
  vector<long long> h(n);
  for(int i = 0;i < n;i++){
    cin >> h.at(i);}
  vector<long long> t(n);
  for(int i = 0;i < n;i++){
    cin >> t.at(i);}
  sort(h.begin(),h.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  long long ng = -1;
    long long ok = 1000000000000;
  while(abs(ng-ok) > 1){
    long long mid = (ng+ok)/2;
    if(hhhh(t,h,mid)<=k)ok = mid;
    else{ng = mid;}
  }
  cout << ok << endl; 
}