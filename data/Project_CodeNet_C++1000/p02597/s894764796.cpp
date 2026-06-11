#include <iostream>
using namespace std;

int main() {
    int ans=0, N, i, num_r=0, num_w = 0, c;
    string S;
    cin >> N;
    cin >> S;
    int *loc_w = new int[N];
    int *loc_r = new int[N];
    for(i=0; i<N; i++){
        c = S[i];
        if( c=='W') {
            loc_w[num_w++] = i;
            //cout << i << endl;
        }else {
            loc_r[num_r++] = i;
        }
    }
    int iter = min(num_w, num_r);
    for( i=0; i<iter; i++){
        //printf("w:%d, r:%d\n", loc_w[i], loc_r[num_r - i-1]);
        if( loc_w[i] > loc_r[num_r - i-1]){
            //flag = 0;
            break;
        }
    }
    cout << i << endl;
}