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

int main(){
    FASTIO
    string s;
    cin>>s;
    int n=s.size();
    if(s[n-1]=='s') s+="es";
    else s+='s';
    cout<<s<<endl;
    return 0;
}
