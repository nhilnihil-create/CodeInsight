#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    ll d;cin>>d;
    double x,y,rj=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(sqrt((x*x)+(y*y))<=d){
            rj++;
        }
    }
    cout << rj<<endl;
}
