//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

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

signed main(){
    int N,M;
    cin>>N>>M;
    int H[100001];

    for(int i=1;i<=N;i++){
        cin>>H[i];
    }

    vector<int> v[100001];
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        bool f=true;
        for(int j=0;j<v[i].size();j++){
            if(H[i]<=H[v[i][j]]) f=false;
        }
        if(f) ans++;
    }
    cout<<ans<<endl;
}
