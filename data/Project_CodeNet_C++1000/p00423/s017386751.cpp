#include <iostream>

using namespace std;

main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;

    int ans1=0, ans2=0;
    for(int i=0;i<n;i++){
      int a, b;
      cin >> a >> b;
      if(a>b){
	ans1+=a+b;
      }else if(a<b){
	ans2+=a+b;
      }else{
	ans1+=a;
	ans2+=b;
      }
    }
    printf("%d %d\n", ans1, ans2);
  }
  return 0;
}