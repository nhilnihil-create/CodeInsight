#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int s,w;
    cin>>s>>w;
    if(w>=s){
        cout<<"unsafe"<<endl;
    }
    else{
        cout<<"safe"<<endl;
    }
}