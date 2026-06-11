#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;
bool is_palin(string s){
    string a=s;
    reverse(a.begin(),a.end());
    return a==s;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    string s;
    cin>>s;
    if(!is_palin(s)){
        cout<<"No"<<endl;
        return 0;
    }
    int n=s.size();
    string a=s.substr(0,(s.size()-1)/2);
    string b=s.substr(((n+3)/2)-1,s.size());
    if(is_palin(a)&&is_palin(b)){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}
