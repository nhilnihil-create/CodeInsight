#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >



int main()
{
    vector<int> v;
    string s;
    int n;
    s+='*';
    s+='*';
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='A')
            v.push_back(i);
    }
    int ans=0;
    for(auto x:v){
        if(s[x+1]=='B' && s[x+2]=='C')
        ans++;

    }
    printf("%d",ans);

}
