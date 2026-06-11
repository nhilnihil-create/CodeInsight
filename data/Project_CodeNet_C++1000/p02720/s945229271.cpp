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
 using vll = vector<bigint> ;
vll v ;
void lunlunNumbergenerator( bigint N ){
    if( N > 1e11 )
        return ;
    v.push_back(N) ;
    int d = N % 10 ;
    if( d == 0 ){
        lunlunNumbergenerator(N*10+1) ;
        lunlunNumbergenerator(N*10) ;
    }
    else if( d == 9 ){
        lunlunNumbergenerator(N*10+d) ;
        lunlunNumbergenerator(N*10+d-1) ;
    }
    else if( d == 1 ){
        lunlunNumbergenerator(N*10) ;
        lunlunNumbergenerator(N*10+1) ;
        lunlunNumbergenerator(N*10+2) ;
    }
    else{
        lunlunNumbergenerator(N*10+d-1) ;
        lunlunNumbergenerator(N*10+d+1) ;
        lunlunNumbergenerator(N*10+d) ;
    }
}
 
 int main(){
     for( bigint i = 1 ; i < 10 ; i++ )
         lunlunNumbergenerator(i) ;
     sort( v.begin() , v.end()) ;
     int N ; cin >> N ;
     cout << v[N-1] << endl ;
     return 0 ;
 }