#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    
    double N;
    cin >> N;
    
    double c=0;
    for(int i=1; i<=N; i++){
        if(i % 2 == 1) c++;
    }
    
    cout << fixed << setprecision(10) << c / N << endl;
    
    return 0;
}
