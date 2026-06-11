#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2){
        string s;
        cin>>s;
        cout<<"No"<<endl;
    }
    else {
        char x;
        int flag=0;
        map<char, int>mp;
        for(int i=0; i<n; i++) {
            cin>>x;
            mp[x]+=1;
        }
        for(auto i: mp) {
            if(i.second%2) {
                flag=1;
                break;
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
