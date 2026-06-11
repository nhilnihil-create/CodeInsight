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
    int N;
    cin>>N;
    string S;
    cin>>S;

    int ans=0;
    for(int i=0;i<=999;i++){
        int a=i/100%10;
        int b=i/10%10;
        int c=i/1%10;
        for(int j=0;j<S.size();j++){
            if(a!=-1){
                if(S[j]-'0'==a) a=-1;
            }
            else if(b!=-1){
                if(S[j]-'0'==b) b=-1;
            }
            else if(c!=-1){
                if(S[j]-'0'==c) c=-1;
            }
        }
        if(c==-1) ans++;
    }
    cout<<ans<<endl;
}
