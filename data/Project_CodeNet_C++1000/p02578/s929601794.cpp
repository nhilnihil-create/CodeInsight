#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define ld long double
#define pb push_back
const int mod=1e9+7;
const int mxN=2e6+3;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }

    long long sum=0;
    for(int i=0,maxnum=0;i<n;i++){
        maxnum=max(a.at(i),maxnum);
        sum+=maxnum-a.at(i);
    }
    cout<<sum<<endl;
    return 0;
}