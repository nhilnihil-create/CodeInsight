#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
typedef long long int lli;
int main(){
    FIO
    int n; cin>>n;
    string s; cin>>s;
    int c=0;
    fo(i,n){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') c++;
    }
    cout<<c<<endl;
}

