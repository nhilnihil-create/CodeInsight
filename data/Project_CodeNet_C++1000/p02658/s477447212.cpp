#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    cin >> N ;
    
    vector<long long> A(N) ;
    
    for( int i=0 ; i<N ; i++){
        cin >> A.at(i) ;
    }
    vector<double> B(N) ;
    for( int i=0 ; i<N ; i++){
        B.at(i) = log10( A.at(i) ) ;
    }
    
    long long count=1 ;
    double logcount=0 ;
    
    for( int i=0 ; i<N ; i++){
        if( A.at(i) == 0 ){
            count = 0 ;
            break;
        }
    }
    
    if( count == 0 ){
        cout << 0 << endl;
    }
    else{
        for( int i=0 ; i<N ; i++){
            count *= A.at(i) ;
            logcount += B.at(i) ;
            
            if( count > 1000000000000000000 ){
                count = -1 ;
                break;
            }
            else if( logcount > 18 ){
                count = -1 ;
                break;
            }
        }
        cout << count << endl;
    }
}
