#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int ans;
    ans=((b-1)+(a-1)-1)/(a-1);
    cout<<ans<<endl;
    return 0;
}