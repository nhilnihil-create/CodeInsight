#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,a,i,k,l;
  cin>>n;
  map<int,int> m;
  for(i=0;i<n;i++){
    cin>>a;
    if(m.count(a)) m.at(a)++;
    else m[a]=1;
  }
  l=m.size();
  vector<int> b(l),s(l);
  i=0;
  for(auto mm:m){
    b.at(i)=mm.second;
    i++;
  }
  sort(b.begin(),b.end());
  s.at(0)=b.at(0);
  for(i=1;i<l;i++) s.at(i)=s.at(i-1)+b.at(i);
  for(k=1;k<=n;k++){
    if(k>l) cout<<0<<endl;
    else if(k==l) cout<<b.at(0)<<endl;
    else{
      int ll=0;
      int rr=n/k+1;
      while(rr-ll>1){
        int mm=(ll+rr)/2;
        int d=distance(b.begin(),lower_bound(b.begin(),b.end(),mm));
        if(d==0 || s.at(d-1)+mm*(l-d)>=k*mm) ll=mm;
        else rr=mm;
      }
      cout<<ll<<endl;
    }
  }
}