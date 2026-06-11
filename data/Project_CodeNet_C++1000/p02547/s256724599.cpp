#include <iostream>
#include <cstring>
using namespace std;
int a[1000][2];
bool st[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;++j){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i][0]==a[i][1])st[i]=1;
    }
    bool t=0;
    int sum=0;
    for(int i=1;i<=n;++i){
        if(st[i]){
            sum++;
            if(sum==3){
                cout<<"Yes"<<endl;
                return 0;
            }
        }else sum=0;
    }
    cout<<"No"<<endl;
}