#include <bits/stdc++.h>

using namespace std;

int main()
{
int K,X;
cin>>K>>X;
if(K!=0&&X!=0&&K<=100&&X<=100000){
if((K*500)>=X){
    cout<<"Yes";
}
else{
    cout<<"No";
}
}
return 0;
}