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
    int N;
    cin >> N;
    int B[N-1];
    rep(i,N-1) cin >> B[i];
    vector<int> v;
    rep(i,N){
        if(i==0){
            v.push_back(B[i]); 
        }
        else if(i==N-1){
            v.push_back(B[i-1]); 
        }
        else if(B[i]>=B[i-1]){
            v.push_back(B[i-1]); 
        }
        else{
            v.push_back(B[i]); 
        }
    }
    int ans =0;
    rep(i,N) ans += v[i];
    cout << ans << endl;
    return 0;
}

