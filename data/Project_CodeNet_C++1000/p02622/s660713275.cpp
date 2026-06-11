#include <iostream> 
#include <cstring> 
using namespace std ; 
int main () {

int x = 0 , y = 0 ; 
char S[200001] , T[200001] ; 
cin >> S ; 
cin >> T ; 
for (int i = 0 ; i<= strlen(S) ; i++){
if (S[i] == T[i]) y++ ; 
else x++ ; } 
if (0==x && 0 == y ) cout << y ; 
else cout<< x ; 
return 0 ; 
}