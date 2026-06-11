#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for(ll i=s;i<e;++i)

int main(){
    int n;
    cin >> n;

    int cnt=0;
    F(i,0,n){
        int d1,d2;
        cin >> d1 >> d2;
        if(d1==d2) ++cnt;
        else cnt=0;
        if(cnt==3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}