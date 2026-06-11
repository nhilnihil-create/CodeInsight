#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char,int> m;
    for(int i=0;i<4;i++){
        char c;
        cin>>c;
        m[c]++;
    }
    for(auto p : m){
        if(p.second==2&&m.size()==2){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}