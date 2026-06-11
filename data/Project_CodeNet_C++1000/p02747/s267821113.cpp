#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int flag=1;
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]!='h') flag=0;
        }
        else{
            if(s[i]!='i') flag=0;
        }
    }
    if(s.size()%2!=0) flag=0;
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}