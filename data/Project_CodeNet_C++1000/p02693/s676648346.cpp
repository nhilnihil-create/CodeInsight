#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
typedef pair<int,int> P;
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  int k,a,b;
  cin>>k>>a>>b;
  
  for(int i=a;i<=b;i++)
    if(i%k==0){
    cout<<"OK"<<endl;
    return 0;
    }
  cout<<"NG"<<endl;
return 0;
}