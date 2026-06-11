#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long int sm = 0 ;
    for(int  i= 0  ; i < s.length() ; i++)sm += s[i] - '0';
    (sm % 9 == 0) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
}
