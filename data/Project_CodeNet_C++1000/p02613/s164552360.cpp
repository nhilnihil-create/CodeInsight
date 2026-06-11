#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n ,ac=0,wa=0,tle=0,re=0;
    cin>>n;
    vector<string> vt(n);
    REP(i,n) {
        cin>>vt.at(i);
        if(vt.at(i)=="AC") ac++;
        else if(vt.at(i)=="WA") wa++;
        else if(vt.at(i)=="TLE") tle++;
        else if(vt.at(i)=="RE") re++;
    }

    cout<<"AC x "<<ac<<"\n";
    cout<<"WA x "<<wa<<"\n";
    cout<<"TLE x "<<tle<<"\n";
    cout<<"RE  x "<<re<<endl;


    

    return 0;
    
    
}