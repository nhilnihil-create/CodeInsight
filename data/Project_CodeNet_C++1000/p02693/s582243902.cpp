#include <iostream>
using namespace std;
int main(){
     int K,A,B,flag=0;
     cin >> K >> A >> B;
     for (int i=0;i<=B-A;i++)if ((A+i)%K==0)flag++;
     if(flag!=0){
          cout <<"OK"<<endl;
     }else{
          cout <<"NG"<<endl;
     }
}
