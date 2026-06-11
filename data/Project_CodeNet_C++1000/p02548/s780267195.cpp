#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(n-1)/i;
    }
    cout<<cnt<<endl;
    //getchar();
    //getchar();
    return 0;
}