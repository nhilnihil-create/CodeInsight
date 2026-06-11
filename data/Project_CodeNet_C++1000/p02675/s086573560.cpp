#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string ans;
    cin>>n;

    int m=n%10;
    if(m==2||m==4||m==5||m==7||m==9) ans="hon";
    else if(m==0||m==1||m==6||m==8) ans="pon";
    else ans="bon";

    cout<<ans<<endl;
}