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

ll A[200000];
int N;
int K;
int Ans;

int main(int argc, const char * argv[]) {

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    for(int i=0; i<N; i++){
        if(A[i] >= K) Ans++;
    }
    
    cout << Ans << endl;
    
    return 0;
}
