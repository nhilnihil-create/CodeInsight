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
    LL a,b,n;
    cin>>a>>b>>n;

    if(n<b){
        cout<<a*n/b<<endl;
    }else{
        cout<<a*(b-1)/b<<endl;
    }
    return 0;
}