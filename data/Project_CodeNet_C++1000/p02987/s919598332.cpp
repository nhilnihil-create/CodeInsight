#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char a,b,c,d; cin>>a>>b>>c>>d;
  if(a==b){
    if(a!=c&&c==d) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }else{
    if((a==c&&b==d)||(a==d&&b==c)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}