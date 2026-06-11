#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=2000;i++){
        int x=i*0.08;
        int y=i*0.1;
        if(x==a&&y==b){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}