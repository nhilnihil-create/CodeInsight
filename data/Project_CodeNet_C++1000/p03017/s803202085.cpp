#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    string s;cin>>s;
    int cb=0;
    for(int i=a-1;i<c;i++){
        if(s[i]=='#') cb++;
        else cb=0;
        if(cb>=2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cb=0;
    for(int i=b-1;i<d;i++){
        if(s[i]=='#') cb++;
        else cb=0;
        if(cb>=2){
            cout<<"No"<<endl;
            return 0;
        }
    } 
    if(c>d){
        int cm=0;
        for(int i=b-1;i<d;i++){
            if((i==b-1||i==d-1)&&(s[i-1]=='.'&&s[i+1]=='.')){
                cout<<"Yes"<<endl;
                return 0;
            }
            if(s[i]=='.') cm++;
            else cm=0;
            if(cm>=3){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}