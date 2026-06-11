#include <bits/stdc++.h>

using namespace std;
int main(){
   
    string s;
    cin>>s;
  long long int count=0,ans=0,i;
   
    for(long long int i = 0;i<s.length();i++){
        if(s[i] == 'R'){
            count++;
        }
        else{
            ans = max(ans,count);
            count = 0;
        }
    }
    ans=max(ans,count);
    cout<<ans<<"\n";
   return 0;
}