#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

bool comp(vll a,vll b){
    return a[1]<b[1];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,K;
    cin>>N>>K;
    
    if(K>(N-1)*(N-2)/2){
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<N-1+(N-1)*(N-2)/2-K<<endl;
    for(int i=2;i<=N;i++){
        printf("%d %d\n",1,i);
    }
    
    ll count=0;
    for(int i=2;i<=N-1;i++){
        if(count==(N-1)*(N-2)/2-K)break;
        for(int j=i+1;j<=N;j++){
            if(count==(N-1)*(N-2)/2-K)break;
            printf("%d %d\n",i,j);
            count++;
        }
    }
    
    return 0;
}
