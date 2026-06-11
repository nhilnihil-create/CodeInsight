#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>

#define A_P(n,a,d) (n/2)*(2*a + (n-1)*d)
using namespace std;
long nCr(int n, int r){
    if(n == r) 
        return 1;
    long dividend = 1;
    long divisor  = 1;
    for ( int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}



//ちゃんとlong型でやってる？

int main(void){
    map<int,int> balls;
    int N;
    cin >> N;
    vector<long> henteko;
    for(int i =0; i < N; i++){
        int tmp;
        cin >> tmp;
        balls[tmp] += 1;
        henteko.push_back(tmp);
    } 
    long sum = 0;
    
    for(auto it = balls.begin(); it != balls.end(); ++it){
        long tmp = nCr(it->second,2); 
        sum += tmp;
    }
    
    for(int i =0 ; i < henteko.size(); i++){
        if(balls[henteko[i]] > 1){
            cout << sum - (nCr(balls[henteko[i]],2)) + (nCr(balls[henteko[i]] - 1,2)) << endl;
        }else{
            cout << sum << endl;
        }
    }
    return 0;
}