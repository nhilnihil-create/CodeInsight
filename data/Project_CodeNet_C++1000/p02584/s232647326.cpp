#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  long long int x,k,d;
  cin>>x>>k>>d;
  double c=0;
  if(x>=0){
    double n=-1-x;
    c=ceil(abs(n/d));
    long long int l;
    if(c<=k){
     l=k-c;
     x=x-(c*d);
   long long  int r=x+d;
    if(l%2==0)
        cout<<abs(x);
    else
        cout<<abs(r);
  }
  else{
    x=x-(k*d);
    cout<<abs(x);
  }
  }
  else{
     double n=1+x;
    c=ceil(abs(n/d));
    long long int l;
    if(c<=k){
     l=k-c;
     x=x+(c*d);
   long long  int r=x-d;
    if(l%2==0)
        cout<<abs(x);
    else
        cout<<abs(r);}
        else{
           x=x+(k*d);
           cout<<abs(x);
        }
  }
}
