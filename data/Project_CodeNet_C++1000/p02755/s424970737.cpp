#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

int main(){
    int a,b;cin>>a>>b;
    int ans=0;
    for(int i=1;i<10000;i++){
        if(i*8/100==a && i*10/100==b){
            ans=i;
            break;
        }
        if(i==9999) ans=-1;
    }
    cout<<ans<<endl;
}