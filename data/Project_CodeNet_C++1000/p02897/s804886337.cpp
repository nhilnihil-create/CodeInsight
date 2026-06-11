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
    if(N%2==0) cout << fixed << setprecision(10) << (double)(N/2.0)/N << endl;
    else cout << fixed << setprecision(10) << (double)(N+1)/2/N << endl;
    return 0;

}