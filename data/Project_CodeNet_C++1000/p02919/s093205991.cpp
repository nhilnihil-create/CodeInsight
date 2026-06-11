#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll p[n];
  for(int i=0;i<n;i++)cin >> p[i];

  ll s=0;

  for(int i=0;i<n;i++){
    if(p[i]==n)continue;
    ll a=i,b,c=i,d;
    ll q=0,r=0;
    while(a<n && p[a]<=p[i]){
      a++;
    }
    if(a==n){
      a--;
      q=1;
    }
    b=a+1;
    while(b<n && p[b]<=p[i]){
      b++;
    }
    /*if(b==n){
      q=2;
      b--;
    }*/
    while(c>-1 && p[c]<=p[i]){
      c--;
    }
    if(c==-1){
      r=1;
      c++;
    }
    d=c-1;
    while(d>-1 && p[d]<=p[i]){
      d--;
    }
    /*if(d==-1){
      r=2;
      d++;
    }*/
    if(q==1){
      s+=(a-i+1)*(c-d)*p[i];
    }
    else if(r==1){
      s+=(i-c+1)*(b-a)*p[i];
    }
    else{
      s+=((a-i)*(c-d)+(i-c)*(b-a))*p[i];
    }
  }
  cout << s << endl;

}