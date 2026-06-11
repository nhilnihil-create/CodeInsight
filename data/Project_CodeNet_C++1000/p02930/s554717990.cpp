#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int k=ceil(log2((double) n));
  //  cout << k << endl;
  rep(i,n-1){
    for(int j=i+1;j<n;j++){
      rep(l,k){
	//	cout << (i&(1<<l)) << " " << (j&(1<<l)) << endl;
	if((i&(1<<l)) != (j&(1<<l)) ){
	  cout << l+1 << " ";
	  break;
	}
      }
    }
    cout << "" << endl;
  }
  

  
  return 0;
    

}
