#include <iostream>
#include <string>
using namespace std;
int main(){
     string S,T;
     int flag =0;
     cin >>S >> T;
     for (int i=0;i<S.length();i++){
          if (S[i]!=T[i]){
               flag++;
               break;
          }
     }
     if (flag != 0){
          cout << "No" <<endl;
     }else{
          cout <<"Yes" <<endl;
     }

}
