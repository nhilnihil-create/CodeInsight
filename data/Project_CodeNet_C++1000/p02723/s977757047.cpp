
#include <bits/stdc++.h>
using namespace std;

int main()

{
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[2]==s[3] && s[4]==s[5]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

}


