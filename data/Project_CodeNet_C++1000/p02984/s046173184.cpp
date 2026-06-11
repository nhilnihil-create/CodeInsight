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
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=1<<18;


int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    ll sum=0;
    vector<ll> even(1,0);
    vector<ll> odd(1,0);
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(i%2==0){
            even.push_back(*even.rbegin()+a[i]);
        }else{
            odd.push_back(*odd.rbegin()+a[i]);
        }
    }

    vector<ll> b(n,0);
    for(int i=0;i<n;i++){
        if(i%2==0){
            b[i]+=*even.rbegin();
            b[i]-=even[(i+2)/2-1];
            b[i]+=odd[(i+2)/2-1];
        }else{
            b[i]+=*odd.rbegin();
            b[i]-=odd[(i+2)/2-1];
            b[i]+=even[(i+2)/2];
        }
        b[i]*=2;
        b[i]-=sum;
    }
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<endl;

}