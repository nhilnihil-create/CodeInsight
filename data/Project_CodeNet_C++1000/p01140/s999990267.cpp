#include <iostream>
#include <map>
using namespace std;
int main()
{
  int a[1501];
  int n,m,i,j,c;
  for(;;){
    cin >> n >> m;
    if(n==0 && m==0) break;
    map<int,int> hm,wm;
    for(i=1;i<=n;i++){
      cin >> a[i];
      a[i] += a[i-1];
      for(j=0;j<i;j++){
	hm[a[i]-a[j]]++;
      }
    }
    for(i=1;i<=m;i++){
      cin >> a[i];
      a[i] += a[i-1];
      for(j=0;j<i;j++){
	wm[a[i]-a[j]]++;
      }
    }
    map<int,int>::iterator it = hm.begin();
    c = 0;
    while(it != hm.end()){
      c += wm[(*it).first] * (*it).second;
      it++;
    }
    cout << c << endl;
  }
  return 0;
}