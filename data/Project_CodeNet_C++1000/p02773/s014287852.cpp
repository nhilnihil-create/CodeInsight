#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long

int main() {
    int n;
    cin>>n;string s;
    map<string,int>m;
    while(n--)
    {
        cin>>s;
        m[s]+=1;
    }int mmm=0;
 for (auto& x: m) {
     if(x.second>mmm)mmm=x.second;
 }
       
       vector<string>A; 
for (auto& it :m) { 
    if(it.second==mmm)
        A.push_back(it.first); 
    } 
     sort(A.begin(), A.end());
     
    
      REP(i,A.size())
      {
          cout<<A[i]<<endl;
      }}
          
          
          
    