#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=2;i<n;i++){
        string tmp;
        tmp+=s[i-2];
        tmp+=s[i-1];
        tmp+=s[i];
        if(tmp=="ABC"){
            ans++;
        }
    }
    cout<<ans<<endl;
}
