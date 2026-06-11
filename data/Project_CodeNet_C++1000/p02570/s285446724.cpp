#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    double D, T, S;
    string ans;
    cin >> D >> T >> S;
  
   if (D/S <= T) ans = "Yes";
   else ans = "No";

   cout << ans << endl;
}