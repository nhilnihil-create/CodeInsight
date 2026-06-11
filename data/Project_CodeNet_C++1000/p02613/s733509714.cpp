#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main(){
    int n;
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    cin>>n;
    string s;

    rep(i,n){
        cin>>s;
        if(s=="AC") cnt1++;
        else if(s=="WA") cnt2++;
        else if(s=="TLE") cnt3++;
        else if(s=="RE") cnt4++;
    }
    cout<<"AC  x  "<<cnt1<<endl;
    cout<<"WA  x  "<<cnt2<<endl;
    cout<<"TLE  x  "<<cnt3<<endl;
    cout<<"RE  x  "<<cnt4<<endl;
    return 0;
}