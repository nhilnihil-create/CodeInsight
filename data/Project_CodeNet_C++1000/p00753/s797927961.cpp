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
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;

bool is(int n){
    if(n==1)return false;
    if(n==2)return true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

bool pri[300000];
void solvePrime(){
    rep(i,300000){
        pri[i]=is(i);
    }
}


int main(){
    solvePrime();
    
    int a;
    
    while(cin>>a){
        int c=0;
        if(a==0)break;
        for(int i=a+1;i<=a*2;i++){
            if(pri[i])c++;
        }
        cout<<c<<endl;
    }
    return 0;
}