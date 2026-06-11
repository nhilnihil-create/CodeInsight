#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 100000000000007
using namespace std;
using pii=pair<int,int>;
using LL=int64_t;




int main(){
    int n;
    map<LL,int> L,R;
    
    cin>>n;
    REP(i,n){
        int a;
        cin>>a;
        L[i+a]++;
        R[i-a]++;
    }

    int64_t ans=0;
    for(int x=-n-1;x<2*n+1;x++){
        if(L.count(x)&&R.count(x)){
            ans+=L.at(x)*R.at(x);
        }
        
    }
    cout<<ans<<endl;
    return 0;
}