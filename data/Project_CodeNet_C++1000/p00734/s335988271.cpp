#include <iostream>

using namespace std;

main(){
  int n, m;
  int ns, ms;
  int d2[100], d1[100];
  while(1){
    cin >> n >> m;
    if(n==0 && m==0) break;
    ns=ms=0;
    for(int i=0;i<n;i++){
      cin >> d1[i];
      ns+=d1[i];
    }
    for(int i=0;i<m;i++){
      cin >> d2[i];
      ms+=d2[i];
    }
    int a1=1000, a2=1000;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	int t1=ns, t2=ms;
	t1-=d1[i];
	t2+=d1[i];
	t1+=d2[j];
	t2-=d2[j];
	if(t1==t2){
	  if(a1+a2>d1[i]+d2[j]){
	    a1=d1[i];
	    a2=d2[j];
	  }
	}
      }
    }
    if(a1==1000 || a2==1000){
      cout << -1 << endl;
    }else{
      cout << a1 << ' ' << a2 << endl;
    }
  }
  return 0;
}