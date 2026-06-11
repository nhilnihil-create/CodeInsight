//
//  main.cpp
//  ABC136C
#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int>h(n);
    rep(i,n) cin>>h.at(i);
    for(int i=n-2;i>=0;i--){
        if(h.at(i)>h.at(i+1)){
            h.at(i)--;
            if(h.at(i)>h.at(i+1)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
