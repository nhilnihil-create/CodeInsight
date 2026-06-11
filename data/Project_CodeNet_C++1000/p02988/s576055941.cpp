#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>p(n);
    rep(i,n)cin>>p[i]; 
    int cnt = 0;
    srep(i,1,n-1){
        if(p[i]>min(p[i-1],p[i+1]) && p[i]<max(p[i-1],p[i+1]))cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}