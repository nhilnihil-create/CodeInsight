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


signed main(){
    //(A*x/B)-A*(x/B)
    int A,B,N;
    cin>>A>>B>>N;
    if(B-1>N) cout<<(A*N/B)-A*(N/B)<<endl;
    else cout<<(A*(B-1)/B)-A*((B-1)/B)<<endl;
    return 0;
    for(int i=1;i<100;i++){
        cout<<(A*i/B)-A*(i/B)<<endl;
    }
    /* 5 7 4
0
1
2
2
3
4
0
0
1
2
2
3
4
0*/
}
