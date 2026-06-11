#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>


using namespace std;


#define mod                1000000000000000007
#define pi                 3.1415926535897932384626433832795
#define ll                 long long
#define pb                 push_back
#define pii                pair < int , int >
#define vecsort(v)         sort(v.begin(),v.end())
#define lcm(x,y)           (x/__gcd(x,y))*y
#define forn(i,n)          for(i = 0 ; i < n ; i++)
#define deb(x)             cout << #x << " " << x << endl;
#define vecsum(v)          accumulate(v.begin(), v.end(), 0)
#define T(t)               cout << "Case " << t <<": ";
#define fast_cin           ios_base::sync_with_stdio(false);cin.tie(NULL)


bool seven( int n ){

      while( n ){

          if( n % 10 == 7 )return true;
          n/=10;
      }

      return false;
}

int main() {


    int n ;
    cin >> n ;
    if( seven( n ) == true ){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }





    return 0;
}