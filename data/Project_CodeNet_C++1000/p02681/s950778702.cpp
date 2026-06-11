#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    if(t.size()!=n+1){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
