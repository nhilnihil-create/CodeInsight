#include<bits/stdc++.h>
using namespace std;
int main()
{
        int k;
        string s;
        cin>>k>>s;
        string temp = "";

    if(k>=s.length()){
        cout<<s<<endl;
        return 0;
    }

    for(int i=0;i<k ; i++){
        temp +=s[i];
    }


    temp+="...";

    cout<<temp<<endl;
}
