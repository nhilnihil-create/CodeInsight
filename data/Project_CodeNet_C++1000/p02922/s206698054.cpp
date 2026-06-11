#include <iostream>
 
using namespace std;
 
int main(){
  int A, B;
  cin >> A >> B;
  int ans=1;
  if(B==1){
    printf("0\n");
  }else{
    B -= A;
    while(B>0){
      B -=(A-1);
      ans++;
    }
    printf("%d\n",ans);
  }
}
