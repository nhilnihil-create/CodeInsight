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
    double A[N];
    double sum=0;
    rep(i,N){
        cin >> A[i];
        sum += 1/A[i];
    }
    double ans = 1/sum;
    cout << fixed << setprecision(6) << ans << endl;
    return 0;

}