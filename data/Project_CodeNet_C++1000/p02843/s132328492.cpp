//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>

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
    int X;
    cin>>X;
    int n=X/100;
    int t=X%100;
    n-=t/5;
    t%=5;
    n-=t/4;
    t%=4;
    n-=t/3;
    t%=3;
    n-=t/2;
    t%=2;
    n-=t/1;
    t%=1;
    if(n>=0) cout<<"1"<<endl;
    else cout<<"0"<<endl;
}
