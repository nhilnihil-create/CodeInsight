#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, m1, h2, m2, k;
    cin >>h1>>m1>>h2>>m2>>k;

    int time1=h1*60+m1;
    int time2=h2*60+m2;

    int time=time2-time1;

    if(time>=k){
        cout << time-k <<endl;
    }
    else {
        cout<<0<<endl;
    }
}