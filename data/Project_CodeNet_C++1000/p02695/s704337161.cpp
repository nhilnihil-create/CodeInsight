//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<climits>

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

int dat[100];
int N,M,Q;
int a[100],b[100],c[100],d[100];

int dfs(int n,int k){
    int ans=0;
    if(k==N+1){
        //cout<<dat[1]<<","<<dat[2]<<","<<dat[3]<<endl;
        for(int i=0;i<Q;i++){
            //cout<<i<<","<<dat[b[i]]<<","<<dat[a[i]]<<","<<c[i]<<endl;
            if(dat[b[i]]-dat[a[i]]==c[i]) ans+=d[i];
        }
        //cout<<ans<<endl;
        return ans;
    }
    for(int i=n;i<=M;i++){
        dat[k]=i;
        ans=max(ans,dfs(i,k+1));
    }
    return ans;
}
signed main(){
    cin>>N>>M>>Q;
    for(int i=0;i<Q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    cout<<dfs(1,1)<<endl;
}
