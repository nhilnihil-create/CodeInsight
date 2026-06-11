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
     int N , M ; cin >> N >> M ;
     map<int , int> m ;
     bool flag = true ;
     for( int i = 0 ; i < M ; i++ ){
         int x , y ; cin >> x >> y ;
         x-- ;
         if( m.find(x) == m.end() ){
             m[x] = y ;
         }
         else if( m[x] != y )
             flag = false ;
     }
     if( flag == false ){
         cout << "-1" << endl ;
         return 0 ;
     }
     for( int i = 0 ; i < 10000 ; i++ ){
         int digits = log10(i) + 1 ;
         if( i == 0 )
             digits = 1 ;
         if( digits != N )
             continue ;
         string str = to_string(i) ;
         bool f = true ;
         for( auto x : m ){
             if( str[x.first] - '0' != x.second ){
                 f = false ;
             }
         }
         if( f == true ){
             cout << i << endl ;
             return 0 ;
         }
     }
     cout << "-1" << endl ;
     return 0 ;
 }