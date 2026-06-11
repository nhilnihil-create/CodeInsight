#include <iostream>
using namespace std;
int main(){
   int A , B , C ;
   cin >> A >> B >> C ;
    if (1 <= A && B && C <= 9){
            if (A == B && A == C)
            {
                cout << "No" << endl ;
            }
    else if (A == B || A == C || B == C)

        cout << "Yes" << endl ;
    else

        cout << "No" << endl ;

  }
     return 0;
}
