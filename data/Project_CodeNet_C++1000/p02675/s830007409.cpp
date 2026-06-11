#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin>>s;
    char a[4]={'0','1','6','8'};
    if(s[s.size()-1]=='3'){
        cout<<"bon"<<endl;
        
    }
    else{
        for(int i=0;i<4;++i){
            if(s[s.size()-1]==a[i]){
                cout<<"pon"<<endl;
                return 0;
            }
        }
        cout<<"hon"<<endl;
    }
    return 0;
}