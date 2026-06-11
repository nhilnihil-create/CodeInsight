#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[200010];
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin>>s;
    int len=strlen(s);
    int sum=0;
    for(int i=0;i<len;i++) sum+=s[i]-'0';
    if(sum%9==0){
        cout<<"Yes";
    }
	else{
        cout<<"No";
    }
}