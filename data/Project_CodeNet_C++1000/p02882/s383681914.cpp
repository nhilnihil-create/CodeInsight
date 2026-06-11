#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};


int main(){
    double a,b,x;
    cin >> a >> b >> x;
    if(x > a*a*b / 2){
        double tan = 2*(a*a*b - x) / (a*a*a);
        double res = atan(tan);
        res = res * (180 / M_PI);
        printf("%.12lf\n",res);
    }
    else{
        double tan = (a * b * b) / (2 * x);
        double res = atan(tan);
        res = res * (180 / M_PI);
        printf("%.12lf\n",res);
    }
    return 0;
}
