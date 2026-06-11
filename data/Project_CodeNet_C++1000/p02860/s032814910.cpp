#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,c=0;
    cin>>n;
    string s;
    cin>>s;
    mc map1;
    for(auto x:s)map1[x]++;
    for(auto x:map1){
        if(x.second%2==0){c+=x.second;}
    }
    if(c==n){cout<<"Yes" <<"\n";}
    else{cout<<"No" <<"\n";}
}
