#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    int n;
    string s,t;
    map<string,int> msi;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        if(s=="insert"){
            msi[t]=1;
        }
        else{
            if(msi.find(t)==msi.end()) cout<<"no"<<endl;
            else cout<<"yes"<<endl;
        }
    }
    return 0;
}