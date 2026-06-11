#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    rep(i,s.size()){
        if((i+1)%2==1){
            if(s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
                cout<<"No"<<endl;
                return 0;
            }

        }else{
            if(s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}