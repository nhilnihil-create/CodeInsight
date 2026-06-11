//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(a1>b1){
        swap(a1,b1);
        swap(a2,b2);
    }
    if(a2<b2){
        cout<<0<<endl;
        return 0;
    }
    in xa=t1*a1+t2*a2;
    in xb=t1*b1+t2*b2;
    if(xa<xb){
        cout<<0<<endl;
        return 0;
    }
    if(xa==xb){
        cout<<"infinity"<<endl;
        return 0;
    }
    in d1=t1*(b1-a1);
    in d2=xa-xb;
    if(d1%d2==0){
        cout<<(d1/d2)*2<<endl;
    }
    else{
        cout<<(d1/d2)*2+1<<endl;
    }
}/*
./problem.exe
*/