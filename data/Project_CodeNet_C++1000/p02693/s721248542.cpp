#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;
vector<string>op(mxN);

vector<char>ans;

signed main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if((i%n)==0)
        {
            cout<<"OK"<<endl;
            return 0;
        }
    }
    cout<<"NG"<<endl;
}