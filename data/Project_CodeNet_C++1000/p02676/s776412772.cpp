#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
const int mod=998244353;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    string s;
    cin>>k;
    cin>>s;
    n=s.size();
    if(n<=k)return cout<<s,0;
    for(int i=0;i<k;i++){
    	cout<<s[i];
    }
    cout<<"...";


    

}

