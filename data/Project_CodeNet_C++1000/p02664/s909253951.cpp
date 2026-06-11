#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
 string s;
 cin>>s;
 for(ll i=0;i<s.size();i++)if( s[i] == '?' ) cout<<'D';
 else cout<<s[i];
 cout<<endl;
    return 0;
}
