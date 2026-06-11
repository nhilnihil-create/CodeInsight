#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

void calc(){
    int N;
    cin >> N;
    int x[256];
    int y[256];
    
    
    for(int i = 0 ; i < 256 ; i++ ){
        x[i] = 0;
        y[i] = 0;
    }
    
    
    if( N == 0 )exit(0);
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int min_x = 0;
    int max_x = 0;
    int min_y = 0;
    int max_y = 0;
    
    for(int i = 1 ; i < N ; i ++ ){
        int n_at,d;
        cin >> n_at >> d;
        
        x[i] = x[n_at] + dx[d];
        y[i] = y[n_at] + dy[d];
        
        min_x = min(x[i],min_x);
        max_x = max(x[i],max_x);
        min_y = min(y[i],min_y);
        max_y = max(y[i],max_y);
    }
    
    cout << max_x - min_x + 1 << " ";
    cout << max_y - min_y + 1 << endl;
    
}
int main(void){
    while(true)calc();
    return 0;
}