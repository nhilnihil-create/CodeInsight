#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=4999999996000000001;



int main(){
    int n;
    cin>>n;
    bool f=true;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a%2==0){
            if(a%3>0 && a%5>0){
                f=false;
            }
        }
    }
    if(f){
        cout<<"APPROVED"<<endl;
    }else{
        cout<<"DENIED"<<endl;
    }
}