#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(string s, int st,int ed){
    int flag=1;
    while(st<ed){
        if(s[st]!=s[ed]){
            flag=0;
            break;
        }
        st++;ed--;
    }
    return flag;
}

int main(){
    string S;
    cin>>S;
    int n=S.size();

    if(f(S,0,n-1)*f(S,0,(n-3)/2)*f(S,(n+1)/2,n-1)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

    return 0;
}