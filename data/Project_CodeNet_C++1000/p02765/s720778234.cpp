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
     int n,r,i;
     cin>>n>>r;
     if(n>=10){i=r;}
     else{i=r+100*(10-n);}
     cout<<i <<"\n";

}