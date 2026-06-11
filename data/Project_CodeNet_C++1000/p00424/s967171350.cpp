#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,m,flag,i,j;
  char a,b;
  vector<pair<char,char> > V;
  while(1){
    cin >> n;
    if(n==0) break;
    for(i=0;i<n;i++){
      cin >> a >> b;
      V.push_back(make_pair(a,b));
    }
    cin >> m;
    for(i=0;i<m;i++){
      cin >> a;
      flag=0;
      for(j=0;j<n;j++){
	if(V[j].first==a){
	  cout << V[j].second;
	  flag=1;
	  break;
	}
      }
      if(flag==0) cout << a;
    }
    cout << endl;
    V.clear();
  }
  return 0;
}