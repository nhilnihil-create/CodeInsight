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
    int X;
    cin>>X;
    //cout<<LLONG_MAX<<endl;
    //=9223372036854775807^(1/5)=6208.37506
    for(int A=-3000;A<=3000;A++){
        for(int B=-3000;B<=3000;B++){
            if(A*A*A*A*A-B*B*B*B*B==X){
                cout<<A<<" "<<B<<endl;
                return 0;
            }
        }
    }
}
