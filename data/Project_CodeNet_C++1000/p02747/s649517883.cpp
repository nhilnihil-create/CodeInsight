#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  char a,b;
  rep(i,5){a=0;b=0;
    cin>>a>>b;
    if(a==0)break;
    if(a!='h'||b!='i'){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;return 0;
}
