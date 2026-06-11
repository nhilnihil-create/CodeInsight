#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool check(string s,long long begin,long long end);
int main(){
    string s;
    cin >> s;
    long long size = s.size();
    string l =s.substr(0,(size - 1)/2);
//    string r =s.substr((size + 3)/2,size - (size + 3)/2);
    if(check(s,0,size - 1) && check(s,0,(size - 1)/2 - 1) && check(s,(size + 3)/2 - 1,size - 1)){
        cout << "Yes"<< endl;
    }else{
        cout << "No" << endl;
    }
}
bool check(string s,long long begin,long long end){
    while (begin < end){
        if(s.at(begin++)!=s.at(end--))
            return false;
    }
    return true;
}


