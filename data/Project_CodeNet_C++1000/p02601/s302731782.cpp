#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;
int main() { 
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,k;
  cin>>a>>b>>c>>k; 	 
  while(a>=b && k>0){
    b*=2;
    k--;
  }
  while(b>=c && k>0){
    c*=2;
    k--;
  }
  if(a<b && b<c){
    cout<<"Yes"<<endl;
    }else{
    cout<<"No"<<endl;
    }
return 0; 
}