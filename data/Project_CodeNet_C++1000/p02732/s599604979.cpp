# include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define in freopen( "input.txt" , "r" , stdin );
#define out freopen( "output.txt" , "w" , stdout );

using namespace std ;

int N2 = 2 * ( 1e5 + 7 ) ;

ll N1 = 1e7 + 7 ;

int main( ){

    // in

    // out

    int n ;

    cin >> n ;

    int a[n] ;

    vector<ll>b(N1),c(N1);

    for( int i = 0 ; i < n ; i ++ ){

        cin >> a[i] ;

        b[a[i]] ++ ;

    }

    for( int i = 0 ; i < N1 ; i ++ ){

        if( b[i] == 0 ){

            c[i] = 0 ;

        }else if( b[i] > 0 ){

            c[i] = ( b[i] * ( b[i] - 1 ) ) / 2  ;

        }

    }

    ll sum = 0 ;

    for( int i = 0 ; i < N1 ; i ++ ){

        sum += c[i] ;

    }

    for( int i = 0 ; i < n ; i ++ ){

        cout << sum - ( b[a[i]] - 1 )  << endl ;

    }

}
