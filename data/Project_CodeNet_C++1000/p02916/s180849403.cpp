#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	int a[n];
  	rep(i,n)cin>>a[i];
  
  	int b[n];
  	rep(j,n)cin>>b[j];
  
  	int c[n];
    rep(k,n)cin>>c[k];
  
  int manzoku=0;
  //これは全部足すだけでおｋ
  rep(l,n){
  	manzoku+=b[l];
  }

  //食べ合わせボーナス
  //2個目から数える
  //1個前との差が一つならｃの値を足す
  //a[m-1]-1ってだるいなあ
  for(int m=1;m<n;m++){
  	if(a[m]-a[m-1]==1){
    manzoku+=c[a[m-1]-1];
    }
  }
   	cout<<manzoku<<endl;
      
}