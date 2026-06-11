#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
typedef unsigned long long ll;
typedef long double lb;
using namespace std;
//for (int i=0;i<n;i++){
//
//}

//vector <int> v1;vector <int> v2;vector <ll> v3;vector <int> v4;

void solve(){

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    lb d,t,s,ans;
    cin>>d>>t>>s;
    t=t*60;
    ans=60*d/s;
    if(ans>t) cout<<"No";
    else cout<<"Yes";

return 0;
}
