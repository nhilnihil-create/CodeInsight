#include <iostream>
#include <string>
#include <vector>
#define INF 100000000
using namespace std;
int main(void){
    int N;
    int W[110];
    
    cin >> N;
    for(int i=0;i<N;i++) cin >> W[i]; 
    
    int S1,S2;
    int dist_now = 1000;
    
    for(int T=1;T<N;T++){
        int S1 = 0,S2 = 0;
        for(int i=0;i<T;i++) {
            S1 += W[i];
          //  cout << S1 << " " << W[i] << " " << T << endl;
        }
        for(int j=T;j<N;j++) {
            S2 += W[j];
          //  cout << S2 << " " << W[j] << " " << T << endl;
        }
        int dist = abs(S1-S2);
        if(dist<dist_now) dist_now = dist;
    }

    cout << dist_now;

    return 0;
    
}
