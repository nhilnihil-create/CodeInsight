#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    if (a>b) {
        if (a-(v*t)>=0&&b-(w*t)>=0) {
            if (a-(v*t)>=b-(w*t)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else if (a-(v*t)>=0&&b-(w*t)<0) {
            cout<<"NO"<<endl;
        } else if (a-(v*t)<0&&b-(w*t)>=0) {
            cout<<"YES"<<endl;
        } else {
            if (a-(v*t)<=b-(w*t)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    } else {
        if (a+(v*t)>=0&&b+(w*t)>=0) {
            if (a+(v*t)>=b+(w*t)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else if (a+(v*t)<0&&b+(w*t)>=0) {
            cout<<"NO"<<endl;
        } else if (a+(v*t)>=0&&b+(w*t)<0) {
            cout<<"YES"<<endl;
        } else {
            if (a+(v*t)>=b+(w*t)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
}