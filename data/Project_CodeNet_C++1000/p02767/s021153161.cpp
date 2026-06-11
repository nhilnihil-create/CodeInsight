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

#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

int main(){
    int N;
    cin>>N;
    int X[100];
    for(int i=0;i<N;i++){
        cin>>X[i];
    }

    int mn=INT_MAX;
    for(int i=-10;i<=110;i++){
        int p=i;
        int sum=0;
        for(int j=0;j<N;j++){
            sum+=(p-X[j])*(p-X[j]);
        }
        mn=min(sum,mn);
    }
    cout<<mn<<endl;

}
