#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;

    int count=0,i=0;

    int l=s.size();

    while(i<l){
        if(s[i]!=t[i]){
            count++;
        }
        i++;

    }

    cout<<count<<endl;



    return 0;
}
