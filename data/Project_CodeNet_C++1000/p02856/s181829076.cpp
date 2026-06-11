#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll m,sum=0,csum=0;
  cin >> m;
  ll i;
  for(i=0;i<m;i++){
    ll d,c;
    cin >> d >> c;
    sum+=d*c,csum+=c;
  }
  if(sum%9==0){
    cout << sum/9+csum-2 << endl;
  }
  else{
    cout << sum/9+csum-1 << endl;
  }
}