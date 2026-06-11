#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define ll long long int
using namespace std;

void Solve(  ){
   int n;
   cin >> n;
   string s;
   cin >> s;
   int counter = 0;
   for(int i=0; i+2<n; i++)
   {
       if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
       {
           counter++;
       }
   }
   cout << counter;
}
int main(){
  //  int t;
   // cin >> t;
   // while(t--)
   {
        Solve( );
        cout << '\n';
   }
    return 0;
}
