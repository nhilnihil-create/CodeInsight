#include<iostream>
using namespace std;
main(){
  int n;
  int y,m,d;
  int mln=333*590+1;
  long long t;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> y >> m >> d;
    t=(y-1)/3*590+(y-1)%3*195;
    if(y%3==0) t+=(m-1)*20;
    else{
      if((m-1)%2==1){
	t+=20;
      }
      if(y%3==0)t+=(m-1)*20;
      else t+=(m-1)/2*39;
    }
    t+=d;
    cout << mln-t << endl;
  }
}