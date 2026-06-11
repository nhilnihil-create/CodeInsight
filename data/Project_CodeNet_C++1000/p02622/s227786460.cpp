#include<iostream>
using namespace std;
string s,t;
int main(){
    int i,c=0;
    cin >> s;
    cin >> t;
    for(i=0;(i<s.size())&&(i<t.size());++i){
        if(s.at(i)!=t.at(i)){
            ++c;
        }
    }
    cout << c << endl;


 

}