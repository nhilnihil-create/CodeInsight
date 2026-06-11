#include <iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n,x;
    cin>>n>>x;
    vector<int>l(n);
    rep(i,n)cin>>l[i];
    int cnt = 0, d = 0;
    int i = 0;
    while(d<=x){
        cnt++;
        if(cnt==n+1)
            break;
        d += l[i];
        i++;
    }
    cout<<cnt<<endl;

    return 0;
}