#include<iostream>
using namespace std;
int main(){
    string a,s;
    int cnt=0;
    cin>>a>>s;
    for(int i=0000;i<a.length();i++){
        if(a[i]!=s[i]){
            cnt++;
        }

    }
    cout<<cnt;
}