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
#include<boost/multiprecision/cpp_long long.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Blong long = mp::cpp_long long;
*/

using namespace std;

#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

int main(){
    int N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin>>S;
    S=S+"###";

    bool f=false;

    for(int i=B;i<D;i++){
        if(S[i-1]=='.'&&S[i+1]=='.'&&S[i]=='.') f=true;
        if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.') f=true;
        if(i+1==D||i+2==D) break;
        if(S[i+1]=='.');
        else if(S[i+2]=='.'){
            i++;
        }
        else {
            cout<<"No"<<endl;
            return 0;
        }
    }

    for(int i=A;i<C;i++){
        if(i+1==C||i+2==C) break;
        if(S[i+1]=='.'&&(f||i+1!=D));
        else if(S[i+2]=='.'&&(f||i+2!=D)){
            i++;
        }
        else {
            cout<<"No"<<endl;
            return 0;
        }
    }



    cout<<"Yes"<<endl;


}
