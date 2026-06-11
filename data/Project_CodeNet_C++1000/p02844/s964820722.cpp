#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n,a=0,b=0,c=0,ans=0;
    cin >> n;
    string s,pin;
    cin >> s;
    /*
    rep(i,n-2){
        for(int j=i+1;j<n-1;j++){
            for(int l=j+1;l<n;l++){
               a=s[i]-48;
               b=s[j]-48;
               c=s[l]-48;
               v[100*a+10*c+b]++;
            //    cout << 100*a+10*b+c << endl;
            }
        }
    }
    ans = count(v.begin(),v.end(),0);
    cout << 1000-ans<<endl;
    */
    rep(i,1000){
        if(i<10) pin = "00" +to_string(i);
        else if(i<100) pin = "0"+to_string(i);
        else pin = to_string(i);
        // cout << pin[0] <<pin[1]<<pin[2]<< endl;
        int f=0;
        rep(j,n){
            if(s[j] == pin[f]) f++;
            if(f==3) break;
        }
        if(f==3) ans++;
    }
    cout << ans << endl;
}