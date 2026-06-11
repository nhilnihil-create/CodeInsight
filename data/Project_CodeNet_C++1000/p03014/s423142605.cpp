/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/



int main() {
int H,W;
cin>>H>>W;
string S[H];

rep(i,H){
    cin>>S[i];
}
char grid[H+1][W+1];
rep3(i,H){
    rep3(j,W){
        grid[i][j]=S[i-1][j-1];
    }
}
int left[H+1][W+1];
rep3(i,H){
    left[i][0]=0;
}
int right[H+1][W+2];
rep3(i,H){
    right[i][W+1]=0;
}
int over[H+1][W+1];
rep3(i,W){
    over[0][i]=0;
}
int under[H+2][W+1];
rep3(i,W){
    under[H+1][i]=0;
}
rep3(i,H){
    rep3(j,W){
        if(grid[i][j]=='#'){
            left[i][j]=0;
        }
        else{
            left[i][j]=left[i][j-1]+1;
        }
    }
}
rep3(i,H){
    repr3(j,W){
        if(grid[i][j]=='#'){
            right[i][j]=0;
        }
        else{
            right[i][j]=right[i][j+1]+1;
        }
    }
}
rep3(i,W){
    rep3(j,H){
        if(grid[j][i]=='#'){
            over[j][i]=0;
        }
        else{
            over[j][i]=over[j-1][i]+1;
        }
    }
}
rep3(i,W){
    repr3(j,H){
        if(grid[j][i]=='#'){
            under[j][i]=0;
        }
        else{
            under[j][i]=under[j+1][i]+1;
        }
    }
}
int max_spot=0;
rep3(i,H){
    rep3(j,W){
        if(grid[i][j]=='#')continue;
        max_spot=max(max_spot,left[i][j]+right[i][j]+over[i][j]+under[i][j]-3);
    }
}
cout<<max_spot<<endl;
return 0;
}