#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#define rep(i,N) for(int i=0; i<N;i++)
using namespace std;

int main(){
    int X,N;
    cin>>X>>N;
    vector<int> p(N);
    rep(i,N){
        cin>>p.at(i);
    }
    int ans=0;
    int d=abs(X-ans);
    rep(i,102){
        int c=0;
        rep(j,N){
            if(i==p.at(j)){
                c=1;
            }
        }
        if(c!=1){
            if(abs(X-i)<d){
                d=abs(X-i);
                ans=i;
            }
        }
    }

    cout<<ans<<endl;



    return 0;
}
