#include <bits/stdc++.h>
using namespace std;
#define ll long long




int main() {


        int n , k ;  cin >> n >> k ;

         int Arr [n] ;
          for (int i = 0 ; i < n ; i ++ )
               cin >> Arr[i];

           int  sum = 0 ;
           sort ( Arr , Arr + n ) ;
             for ( int i = 0 ; i < k ; i ++ )
                  sum +=Arr[i];

              cout << sum << endl;
            
        return 0;
    }