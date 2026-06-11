#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int x;
  cin>>x;
  int num=x/100,cur=x%100;
  int temp=0;
  for(int i=5;i>=1;i--){
    temp+=cur/i;
    cur%=i;
  }
  if(num<temp) cout<<"0"<<endl;
  else cout<<"1"<<endl;
  return 0;
}
