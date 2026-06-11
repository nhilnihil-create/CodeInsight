#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
#include <sstream>

using namespace std;



int main (){

   int n,i,j,cnt=0;
   cin>>n;

   int a[n];

   for(i=0;i<n;i++){


       cin>>a[i];

}



   for(i=0;i<n;i++){

       if( a[i]%2 == 1 && (i+1)%2 == 1 )
           cnt++;


   }

   cout<<cnt;






}