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
    int H[N];
    rep(i,N) cin >> H[i];
    int ans=0;
    int s=0;
    while(s<N){
        int l=0;
        while(H[s]>=H[s+1] && s<N-1){
            s++;
            l++;
        }
        s++;
        if(ans<l) ans=l;
    }
    cout << ans << endl;
    return 0;
}