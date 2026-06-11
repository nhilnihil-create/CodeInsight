#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int  N;
    cin >> N;
    for(int i=1 ; i<=N; ++i){
        double P =0;
        int K;
        P=i*1.08;
        K =(int)P;
       if(N ==K){
        cout << i << endl;
        return 0;
        }
    }
    cout << ":(" << endl;
}