#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    string ans="";
    for(int i=0; i<t.size()-1; i++)
        ans+=t[i];
    if(ans==s)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
