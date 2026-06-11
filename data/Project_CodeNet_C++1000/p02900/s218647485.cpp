  //According to all known laws of aviation, there is no way that a bee should be able to fly.
 //Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
 //Because bees don't care what humans think is impossible.
 #include <bits/stdc++.h>
 #define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 #define mod 1000000007
 #define endl "\n"
 using namespace std ;
 using bigint = long long int ;
 using vi = vector<int> ;
 bigint arr[300011] ;

 int main(){
     bigint A , B ; cin >> A >> B ;
     bigint G = gcd( A , B ) ;
     bigint ans = 1 ;
     for( bigint i = 2 ; i * i <= G ; i++ ){
         if( G % i == 0 ){
         while( G % i == 0 ){
             G /= i ;
            }
             ans++ ;
         }
     }
     if( G > 1 )
         ans++ ;
     cout << ans << endl ;
     return 0 ;
 }
