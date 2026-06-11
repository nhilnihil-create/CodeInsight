#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    string s;
    cin>>s;
    int n=s.size();
    int num1=(n-1)/2;
    int num2=(n+3)/2;
    bool d=true;

    rep(i,n){
        if(s.at(i)!=s.at(n-1-i)){
            d=false;
            break;
        }
    }

    rep(i,num1){
        if(s.at(i)!=s.at(num1-1-i)){
            d=false;
            break;
        }
    }
    if(d==false){
        cout<<"No"<<endl;
        return 0;
    }

    if(n-num2==0){
        cout<<"Yes"<<endl;
        return 0;
    }
    rep(i,n-num2){
        if(s.at(num2-1+i)!=s.at(n-1-i)){
            d=false;
        }
    }
    if(d==false){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
}