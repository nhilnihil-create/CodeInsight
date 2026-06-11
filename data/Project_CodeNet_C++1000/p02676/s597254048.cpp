#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int n,a;
    string s;
    cin>>n>>s;
    a=s.size();
    if(a<=n){
        cout<<s<<endl;
    }
    else{
        s[n]='.';
        s[n+1]='.';
        s[n+2]='.';
        for(int i=0;i<n+3;i++){
            cout<<s[i]<<flush;
        }
        cout<<endl;
    }
    return 0;
}
