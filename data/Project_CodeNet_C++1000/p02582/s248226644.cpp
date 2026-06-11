#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      string s;
      cin>>s;
      if(s=="RRR") cout<<3;
      else if(s=="RRS"||s=="SRR") cout<<2;
      else if(s=="SSS") cout<<0;
      else cout<<1;
}