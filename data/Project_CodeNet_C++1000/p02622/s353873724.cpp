# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
 
int main(){
   string s,t;
   cin>>s>>t;
   int count=0;
   for(int i=0;i<s.length();i++){
     if(s[i]!=t[i])count++;
   }cout<<count<<"\n";

}