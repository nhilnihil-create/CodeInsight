#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ret=0;
    for(int i=1;i<n;i++){
        int mx=0;
        int now=0;
        for(int j=0;j<n-i;j++){
            if(now==i||s[j]!=s[j+i]){
                mx=max(mx,now);
                now=0;
            }else{
                now++;
            }
        }
        mx=max(mx,now);
        ret=max(ret,mx);
    }
    cout<<ret<<endl;
}

