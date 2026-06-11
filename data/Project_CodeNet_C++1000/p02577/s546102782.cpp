#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;
    int sum=0;
    for(int i=0;i<str.size();++i){
        sum+=str[i]-'0';
    }
    if(sum%9) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}