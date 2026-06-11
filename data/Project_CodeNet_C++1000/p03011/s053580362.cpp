#include <iostream>
using namespace std;
int main (){
 
 int P,Q,R;
 cin >> P >> Q >> R;
 
 if(P <= Q && R <= Q){
     cout << P + R << endl;
 }
else if(Q <= P && R <= P){
     cout << Q + R << endl;
}
else if(Q <= R && P <= R){
      cout << Q + P << endl;
}
}