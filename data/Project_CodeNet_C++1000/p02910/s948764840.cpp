#include <bits/stdc++.h>
using namespace std;

int main(){
string S;
cin>>S;
int len=S.length();
char s[4]={'R','U','D','L'};
int right=0;
for(int i=0;i<len;i++){
    if(S[i]==s[0]||S[i]==s[1]||S[i]==s[2]||S[i]==s[3]){
        if(i%2==0){
            if(S[i]==s[0]||S[i]==s[1]||S[i]==s[2]){
                right++;
            }
            
        }
        else{
            if(S[i]==s[3]||S[i]==s[1]||S[i]==s[2]){
                right++;
            }
        }
    }
}
if(right==len){
    cout<<"Yes";
}
else{
    cout<<"No";
}
   return 0;
   
}