#include <iostream>
using namespace std;
bool r(int &i,string S);
bool a(int &i,string S);
bool r(int &i,string S){
    while(i<S.size()){
        switch(S[i]){
            case '(':
                i++;
                if(!r(i,S)) return false;
                break;
            case ')':
                i++;
                return true;
            case '[':
                i++;
                if(!a(i,S)) return false;
                break;
            case ']':
                i++;
                return false;
            default:
                i++;
                break;
        }
    }
    return false;
}
 
bool a(int &i,string S){
    while(i<S.size()){
        switch(S[i]){
            case '(':
                i++;
                if(!r(i,S)) return false;
                break;
            case ')':
                i++;
                return false;
            case '[':
                i++;
                if(!a(i,S)) return false;
                break;
            case ']':
                i++;
                return true;
            default:
                i++;
                break;
        }
    }
    return false;
}
 
int main(){
    string str;
    while(true){
        getline(cin,str);
        if(str==".") return 0;
        else str.push_back(']');
        int i=0;
        if(a(i,str)&&i==str.size()){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}