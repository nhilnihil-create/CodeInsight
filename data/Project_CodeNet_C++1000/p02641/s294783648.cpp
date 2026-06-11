#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <set>
#define ll long long
using namespace std;

int main(){
    int X,N;
    cin>>X>>N;
    set<ll> s;
    for(int i=0;i<N;i++){
        int p;
        cin>>p;
        s.insert(p);
    }
    int cnt=0;
    while(1){
        if(!s.count(X-cnt)){
            cout<<X-cnt<<endl;
            break;
        }
        if(!s.count(X+cnt)){
            cout<<X+cnt<<endl;
            break;
        }
        cnt++;
    }
}