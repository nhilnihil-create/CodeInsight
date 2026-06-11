#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int x,n,A,iter=0;
    cin >> x >> n;
    vector<int> p(100,0);
    rep(i,n)  {cin >> A; p[A]++;}
    // rep(i,100) cout <<i<<" "<< p[i] << endl;
    while(1){
        if(p[x-iter] == 0){
            cout<<x-iter<<endl;
            break;
        }
        if(p[x+iter] == 0) {cout<<x+iter<<endl;break;}
        iter++;
    }

}