#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b;
  cin>>r>>g>>b;
  int k;
  cin>>k;
    while(g<=r){k--;g=g*2;}
    while(b<=g){k--;b=b*2;}
    if(k>=0)cout<<"Yes";
    else cout<<"No";
    return 0;
}
