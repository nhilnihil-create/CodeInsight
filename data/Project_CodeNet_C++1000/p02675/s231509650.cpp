#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=n%10;
    if(a==3){
        cout<<"bon";
    }
    else if(a==0||a==1||a==6||a==8){
        cout<<"pon";
    }
    else{
        cout<<"hon";
    }
}
