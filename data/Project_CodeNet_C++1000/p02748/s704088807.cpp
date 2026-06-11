#include <iostream>
using namespace std;

int main(void){
    int A,B,M;
    cin>>A>>B>>M;
    int a[A] = {};
    int b[B] = {};
    int amin=100000,bmin=100000;
    for(int i=0;i<A;i++){
        int ai;
        cin>>ai;
        a[i] = ai;
        amin = min(amin, ai);
    }
    for(int i=0;i<B;i++){
        int bi;
        cin>>bi;
        b[i] = bi;
        bmin = min(bmin, bi);
    }

    int ans = amin + bmin;
    for(int i=0;i<M;i++){
        int x,y,c;
        cin>>x>>y>>c;
        ans = min(ans, a[x-1]+b[y-1]-c);
    }
    cout<<ans<<endl;
}