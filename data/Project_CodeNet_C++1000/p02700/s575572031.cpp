#include <iostream>

using namespace std;

int main(void)
{
 int A,B,C,D;
 cin >> A >> B >> C >> D;
 for(int i=0;i < 150;i++)
 {
   C = C-B;
   if(C <=0)
   {
     cout << "Yes" << endl;
     break;
   }
   A = A-D;
   if(A <=0)
   {
     cout << "No" << endl;
     break;
   }
 }
}