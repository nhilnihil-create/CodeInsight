#include <bits/stdc++.h>
using namespace std;

int main() {
  long A,V;cin>>A>>V;
  long B,W;cin>>B>>W;
  long T;cin>>T;
  long dist;
  bool can;
  if (V<=W) can=false;
  else{
    long catchup=V-W;
    if(A>B) dist=A-B;
    else dist=B-A;
    if(catchup*T>=dist) can=true;
    else can=false;
  }
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

