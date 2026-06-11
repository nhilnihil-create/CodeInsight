#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int main(){
    double a,b,x;cin>>a>>b>>x;




    if(x>=a*a*b/2){
        printf("%.10lf\n",atan(2*(b/a-x/a/a/a))/M_PI*180);
    }else{
        printf("%.10lf\n",atan(a*b*b/2/x)/M_PI*180);
    }


    return 0;
}