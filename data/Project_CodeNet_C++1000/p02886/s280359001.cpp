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
ll Ans;
int N;

void dfs(int num){
    if(num>=N) return;
    
    dfs(num+1);
    
    for(int i=num+1; i<N; i++){
        Ans += A[num] * A[i];
    }
}

int main(int argc, const char * argv[]) {

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    dfs(0);
    
    cout << Ans << endl;
    
    return 0;
}
