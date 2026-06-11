#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    string s;
    cin>>s;
    if(s.size()<5){
        cout<<"No"<<endl;
        return 0;
    }
    if(s[2]==s[3]&&s[4]==s[5]){
        cout<<"Yes"<<endl;
        return 0;
    } 
    cout<<"No"<<endl;
}
