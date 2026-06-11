#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
   int x,y;
   cin >> x >> y;
   int f = 0;
   for (int i = 0; i <= x;i++)
   {
   if(i*2+(x-i)*4==y)
   {
       f = 1;
       break;
   }
   }

    if(!f)
    {

        cout << "No" << endl;
    }else
    {
        cout << "Yes" << endl;
    }
    return 0;
}