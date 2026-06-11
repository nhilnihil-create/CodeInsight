#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    auto i=s.begin();
    auto j=s.end()-1;
    while(i<j){
        if(*i!=*j) cnt++;
        i++;
        j--;
    }
    cout<<cnt<<endl;
}