#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;


int main(){
    int n;
    while(cin>>n){
        int c=0;
        int data[1001][1001]={};
        if(n==0)break;
        
        rep(i,1001){
            data[i][i]=i;
        }
        REP(i,1,1000){
            REP(j,i+1,1000+1){
                data[i][j]=data[i][j-1]+j;
                if(data[i][j]==n){
                    c++;
                }
            }
        }
        cout<<c<<endl;
    }
    
    return 0;
}