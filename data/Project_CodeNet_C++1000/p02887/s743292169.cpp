#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])continue;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}