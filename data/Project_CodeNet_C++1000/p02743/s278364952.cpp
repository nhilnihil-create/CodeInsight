#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF (INT_MAX)
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    long double a,b,c;
    cin>>a>>b>>c;
    long double eps=1.0E-14;
    if(sqrt(a)+sqrt(b)+eps<sqrt(c)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}