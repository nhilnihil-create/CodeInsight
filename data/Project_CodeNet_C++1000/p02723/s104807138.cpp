#include<iostream>
#include<string>
using namespace std;

int main(){
    string temp;
    cin>>temp;
    if(temp[2]==temp[3]&& temp[4] == temp[5])
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
