#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int a,b;
    cin>>a>>b;

    double tax1,tax2;
    tax1=0.08;
    tax2=0.1;
    double ans;

    for(double i=1;i<=1250;i++) {
        double a1=(i*tax1);
        double a2=(i*tax2);
        //cout<<a1<<endl;
        if(double(floor(a1))==a&&double(floor(a2)==b)) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}


