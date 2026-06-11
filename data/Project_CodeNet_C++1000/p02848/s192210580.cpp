#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        int x=s[i]-'A';
        x=(x+n)%26;
        char c=x+'A';
        cout<<c;
    }
    cout<<endl;
    return 0;
}