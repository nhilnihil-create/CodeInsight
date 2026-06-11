#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
string s;
cin>>n>>s;
int w=0;
int ans=0;
for (int i = 0; i < n; i++)
{
    
    
    if(s[i]=='W'){
        w++;
    }
}
 for (int i = 0; i < n; i++)
{
    
    if(i<n-w){
    if(s[i]=='W'){
        ans++;
    }
    }
}
cout<<ans<<endl;

}