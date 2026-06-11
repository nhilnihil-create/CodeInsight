#include <bits/stdc++.h>
using namespace std;
#define ll long long




int main() {

            int n ; cin >> n ;
            int Arr [n+5];
             int cnt = 0 ;
             for ( int i = 1 ; i  <=  n ; i ++ ){
                    cin >> Arr[i];
             }

             for ( int i = 1 ; i <= n ; i+=2){
                 if ( Arr[i] % 2 ==1)
                     cnt ++;
             }
             cout << cnt << endl;

        return 0;
    }