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
    int max=0;
    rep(i,N){
        if(H[i]>max) max=H[i];
        if(max-H[i]>=2){
            puts("No");
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}