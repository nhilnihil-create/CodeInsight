#include <bits/stdc++.h>
using namespace std ;
int main()
{
   int x;
   cin >> x ;
   if(x%10==3){cout<<"bon" ;}
   else if (x%10==2 || x%10==4 || x%10==5 || x%10==7 || x%10==9  )
   {
       cout << "hon" ;
   }
   else {cout << "pon" ;}



    return 0 ;
}
