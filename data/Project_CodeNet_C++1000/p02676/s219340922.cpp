#include<iostream>
using namespace std;
int main(){
    string s;
    int k;
    cin>>k>>s;
    if(s.length()<k){
        cout<<s;
        return 0;
    }
    for(int i=0;i<k;i++){
        cout<<s[i];
    }
    if(s.length()>k){
        cout<<"...";
    }
}    