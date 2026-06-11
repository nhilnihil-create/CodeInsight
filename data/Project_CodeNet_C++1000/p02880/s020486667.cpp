#include <iostream>
using namespace std;

int main()
{
   int N ;
   cin >> N;
   bool is_ok = 0;
   for (int i = 1 ; i <= 9 ; ++i){
      if ((N%i==0) && (N/i <= 9)){
         is_ok = 1;
         break ;
      }
   }
   if (is_ok){
      cout << "Yes" << endl;
   }
   else
   {
      cout << "No" << endl;
   }
}