#include <iostream>
using namespace std;

int main() {
	int	x=0;
  cin>>x;
  bool ok=false;
  if(x==0)
    cout<<"No";
    else{
  for(int i=1; i<10;i++){
  if(x/i<10 && x%i==0){
    ok=true;
    break;}
  
  }
  if(ok)
    cout<<"Yes";
  else
    cout<<"No";
    }
	return 0;
}
