#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    FASTIO
    int n;
    string s,t,ss;
    cin>>n>>s;
    if(n%2) cout<<"No"<<endl;
    else{
        ss=s.substr(0,n/2);
        t=s.substr(n/2,n/2);
        if(ss==t) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
