#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int j=s.size()-1;
    int cnt=0;
    for(int i=0;i<s.size()/2;i++) {

        if(s[i]!=s[j])cnt++;
        j--;
    }
    cout<<cnt<<endl;

}
