#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  string s; cin>>s;
  int n=s.size();
  vector<int> v(n,0);

    int i=0,x;
    while(i<n){
      int c=0;
      while(s[i]=='R'){c++;i++;}
      int x=c; int y=i;
      while(s[i]=='L'){c++;i++;}
      
      if(x%2==0){v[y-1]=c/2;}
      else{v[y-1]=(c+1)/2;}
      v[y]=c-v[y-1];
    }
  rep(i,n){cout<<v[i]<<" ";}

}
