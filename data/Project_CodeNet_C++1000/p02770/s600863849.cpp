#include <iostream>
#include <vector>
using namespace std;


int main() {
    int k, q;
    cin >> k >> q;

    vector<int> raw_ds(k);
    int d;
    for(int i=0;i<k;++i){
        cin >> d;
        raw_ds[i] = d; 
    }

    int n, x, m;
    long long t;
    int num_zero;
    int num_neg;
    long long total;
    
    for(int i=0;i<q;++i){
        cin >> n >> x >> m;

        num_zero = num_neg = 0;
        total = x % m;
        for(int j=0;j<k;++j){
            d = raw_ds[j] % m;
            t = (n-1) / k;
            if( j < (n-1) % k ){
                if ( d == 0 ) num_zero += (t+1);
                total += ( d * (t+1) ) ;
            }else{ 
                if ( d == 0 ) num_zero += t;
                total += ( d * t );
            }
        }
        
        num_neg = total / m;
        
        cout << n - 1 - num_neg - num_zero << endl;
    }

    return 0;
    
}
