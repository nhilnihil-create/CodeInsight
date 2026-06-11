#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int k;
    cin>>k;
    string str;
    cin>>str;
    for (int i=0;i<str.size();i++){
        str[i]+=k;
        if (str[i]>'Z'){
            str[i]=64+(str[i]-'Z');
        }
    }
    cout<<str<<endl;
}