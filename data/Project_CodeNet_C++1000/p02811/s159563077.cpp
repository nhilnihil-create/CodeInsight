#include <iostream>
using namespace std;

int main() {
   int k;
   int x;
   cin>>k>>x;
   int p=500 * k;
   if (p >= x)
   {
       cout<<"Yes";
   }
   else
   {
       cout<<"No";
   }
	return 0;
}