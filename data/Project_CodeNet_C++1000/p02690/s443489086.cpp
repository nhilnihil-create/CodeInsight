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
    int64_t x;
    cin>>x;
    for(int64_t a=-200;a<200;a++){
        for(int64_t b=-200;b<200;b++){
            if(a*a*a*a*a-b*b*b*b*b==x){
                cout<<a<<' '<<b;
                return 0;
            }
        }
    }

    
    return 0;
}