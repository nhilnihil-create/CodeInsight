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
    vector<int> v;
    int N;
    double x[10],y[10];

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
        v.push_back(i);
    }

    double sum=0;
    double c=0;
    do{
        c++;
        for(int i=1;i<v.size();i++){
            sum+=sqrt(pow(x[v[i]]-x[v[i-1]],2)+pow(y[v[i]]-y[v[i-1]],2));
        }
    }while(next_permutation(v.begin(),v.end()));
    printf("%.12f\n",sum/c);
}
