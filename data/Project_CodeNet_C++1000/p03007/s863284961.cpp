#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()
//using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI=3.14159265358979323846;
const int64_t waru = 1000000007;
//const in INF=1<<30;
using vec = vector<vector<int>>;
void in(int &a){int x;cin>>x;a=x;}

int main(){
  int n;
  in(n);
  vector<int> a(n);
  rep(i,n) in(a.at(i));
  sort(all(a));
  int x,y,z;
  if(n==2){
    cout<<abs(a[0]-a[1])<<endl;
    cout<<a[1]<<" "<<a[0];
    return 0;}
  
  if(a[0]>0) x=1;
  else if(a[n-1]<0) x=2;
  else x=3;
  int sum =0;
  
  
  if(x==1){
    rep(i,n-1) sum += a[i+1];
    sum -=a[0];
    cout<<sum<<endl;
    y=a[0];
    rep(i,n-2){
       cout<<y<<" "<<a[i+1]<<endl;
      y -=a[i+1];
    }
    cout<<a[n-1]<<" "<<y<<endl;
  }
  
  if(x==2){
    rep(i,n-1) sum -= a[i];
    sum += a[n-1];
    cout<<sum<<endl;
    y=a[n-1];
    rep(i,n-2){
       cout<<y<<" "<<a[i]<<endl;
      y -=a[i];
    }
    cout<<y<<" "<<a[n-1]<<endl;
  }
  
  if(x==3){
    rep(i,n) sum += abs(a[i]);
    cout<<sum<<endl;
    y=a[0];
    z=a[n-1];
    for(int i=1;i<n-1;i++){
      if(a[i]>=0){cout<<y<<" "<<a[i]<<endl;
                  y -=a[i];
                 }
      else{
         cout<<z<<" "<<a[i]<<endl;
        z -=a[i];
      }
    }
    cout<<z<<" "<<y<<endl;
  }
  
  
  
}

