#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<string> got;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        got.insert(s);
    }
    cout<<got.size()<<"\n";
    return(0);
}