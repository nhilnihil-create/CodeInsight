#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int l,r,d;
   cin >> l >> r >> d;

   int kcount = 0;

   for(int i = l; i <= r; i++){
        if(i % d == 0){
            kcount = kcount +1;
        }
   }

    cout << kcount;

}