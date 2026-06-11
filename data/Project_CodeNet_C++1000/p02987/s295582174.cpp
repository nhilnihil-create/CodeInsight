#include <iostream>
using namespace std;

int main() {
 int seged=0;
 string S="ASSA";
 cin >> S;
 for(int i=0;i<S.length()-1;i++){
   for(int j=i+1;j<S.length();j++){
     if(S[i]==S[j]){
       seged+=1;
     }
   }
 }
 if(seged==2){
   cout << "Yes";
 }else{
   cout << "No";
 }
 	return 0;
}
