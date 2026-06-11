#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int acount=0;
    int bcount=0;
    while(a>0){
        a=a-d;
        acount++;
    }
    while(c>0){
        c=c-b;
        bcount++;
    }
    if(acount>=bcount){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}