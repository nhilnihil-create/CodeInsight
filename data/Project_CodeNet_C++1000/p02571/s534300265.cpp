#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int ans=10000,n=0;
    for(int i=0;i<=s.size()-t.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i+j]!=t[j]){
                n++;
            }
        }
        if(n<ans){
            ans=n;
        }
        n=0;
    }
    cout<<ans<<endl;
    return 0;
}
