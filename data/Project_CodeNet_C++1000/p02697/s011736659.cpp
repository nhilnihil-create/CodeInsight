#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    if(N%2==1){
        for(int i=1; i<=M; ++i){
            cout << i << ' ' << N-i << endl;
        }
    }
    else{
        int g=N/2-1;
        for(int i=1; i<=min(M, (g+1)/2); ++i){
            cout << i << ' ' << g+g%2+1-i << endl;
        }
        for(int i=1; i+(g+1)/2<=M; ++i){
            cout << N+1-i << ' ' << N/2+1-(N/2)%2+i << endl;
        }
    }
    return 0;
}
