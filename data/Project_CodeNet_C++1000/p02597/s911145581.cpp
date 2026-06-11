#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    string s,t;
    int n;
    cin>>n>>s;
    int r=0,w=0,c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            r++;
        }
        else{
            w++;
        }
    }
    for(int i=0;i<n;i++){
        if(i<r){
            t+='R';
        }
        else{
            t+='W';
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            c++;
        }
    }
    cout<<(c+1)/2<<endl;

    return 0;
}
