#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int s[m],c[m];
    for(int i=0;i<m;i++)cin>>s[i]>>c[i];
    for(int i=0;i<=999;i++){
        stringstream ss;ss<<i;
        string str=ss.str();
        if(str.size()!=n)continue;
        bool flag=true;
        for(int j=0;j<m;j++){
            if(str[s[j]-1]!=(char)(c[j]+'0'))flag=false;
        }
        if(flag){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}