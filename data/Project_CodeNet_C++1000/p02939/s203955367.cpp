#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >>s;
    string before="";
    string tmp="";
    before = s.at(0);
    int count =1;
    for(int i=1; i<s.length(); i++){
        if(tmp == ""){
            tmp = s.at(i);
            if(tmp != before){
                before = tmp; count++;
                tmp ="";
            }
        }else{
            tmp = tmp + s.at(i);
            if(tmp != before){
                before = tmp; count++;
                tmp="";
            }
        }
    }
    cout << count << endl;
    return 0;
}