#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int A,B,m;
    cin>>A>>B>>m;

    vector<int> a(A),b(B);
    int lowest_a=100001,lowest_b=100001;
    REP(i,A){
        cin>>a[i];
        if(a[i]<lowest_a){
            lowest_a=a[i];
        }
    }
    REP(i,B){
        cin>>b[i];
        if(b[i]<lowest_b){
            lowest_b=b[i];
        }
    }

    vector<int> x(m),y(m),c(m);
    REP(i,m){
        cin>>x[i]>>y[i]>>c[i];
    }

    int lowest_pair=lowest_a+lowest_b;
    int p=0;
    REP(i,m){
        p=a[x[i]-1]+b[y[i]-1]-c[i];
        if(p<lowest_pair){
            lowest_pair=p;
        }
    }

    cout<<lowest_pair<<endl;
}