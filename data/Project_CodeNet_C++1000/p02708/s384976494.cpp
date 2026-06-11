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
#define INF 1000000007
using namespace std;
using pii=pair<int,int>;
using LL=int64_t;





int main(){
    LL n,k;
    cin>>n>>k;
    
    vector<LL> count(n+2,0);//ちょうどi個選ぶときの和の種類
    REP(i,n+2){
        count.at(i)=i*(n-i+1)+1;
        //cout<<i<<' '<<n-i+1<<' '<<i*(n-i+1)+1<<' '<<count.at(i)<<endl;
        
        count.at(i)%=INF;
    }

    LL ans=0;
    for(int i=k;i<=n+1;i++){
        ans+=count.at(i);
        ans%=INF;
        //cout<<count.at(i)<<endl;
    }
    
    cout<<ans<<endl;
    return 0;
}