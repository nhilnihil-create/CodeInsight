#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    for(int i=a-1;i<c;i++){
        if(s[i]==s[i+1]&&s[i]=='#'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=b-1;i<d;i++){
        if(s[i]==s[i+1]&&s[i]=='#'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(c>d){
        for(int i=b-1;i<d;i++){
            if(s[i-1]==s[i]&&s[i+1]==s[i]&&s[i]=='.'){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }else cout<<"Yes"<<endl;
}