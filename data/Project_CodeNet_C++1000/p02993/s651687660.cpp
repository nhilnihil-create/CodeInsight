#include <iostream>
using namespace std;

int main() {
 bool seged=true;
 string S="8770";
 cin >> S;
 for(int i=0;i<S.length()-1;i++){
   if(S[i]==S[i+1]){
     seged=false;
   }
 }
   if(seged==false){
     cout << "Bad";
   }else{
     cout << "Good";
 } 
	return 0;
}
