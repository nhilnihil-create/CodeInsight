#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main(){
    int p,a=0;
    cin>>p;
    if(3<=p&&p<=20){
    vector<int>n(p);
    for(int i=0;i<p;i++){
        cin>>n.at(i);
    }
    for(int i=0;i<p-2;i++){
        if(n.at(i)<n.at(i+1)&&n.at(i+1)<n.at(i+2)){
            a++;
        }
        else if(n.at(i)>n.at(i+1)&&n.at(i+1)>n.at(i+2)){
            a++;
        }
    }
    std::cout << a << std::endl;
}}