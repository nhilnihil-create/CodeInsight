#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int N,K;
    cin >> N >> K;
    int h[N];
    rep(i,N) cin >> h[i];
    
    int sum=0;
    rep(i,N){
        if(h[i]>=K) sum+=1;
    }
    cout << sum << endl;
    return 0;
}

