#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;

int n;
bool Era[123456*2+1];
int main() {
    Era[0] = Era[1] = false;
    for(int i=2; i<=123456*2+1; ++i) Era[i]=true;
    
    for(int i=2; i*i < 123456*2+1; ++i){
        if(Era[i]){
            for(int j=0; i*(j+2)< 123456*2+1; j++){
                Era[i*(j+2)]= false;
            }
        }
    }   
    while(cin >> n, n){
        int cnt=0;
        for(int i=n+1; i<=2*n; ++i){
            if(Era[i]) cnt++;
        }
        cout << cnt << endl;
    }
        
    return 0;
}
