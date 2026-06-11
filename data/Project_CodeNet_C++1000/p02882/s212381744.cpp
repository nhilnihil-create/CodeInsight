#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<char>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

int main(){
    double  a,b,x;
    cin>>a>>b>>x;
    double s=x/a;
    double rad=0;
    if(s>=a*b/2){
        double h=(a*b-s)*2/a;
        rad=atan2(h,a);
    }else{
        double w=s*2/b;
        rad=atan2(b,w);
    }
    double PI=acos(-1);
    double deg=rad/(2*PI)*360;
    printf("%.10f\n",deg);
    return 0;
}