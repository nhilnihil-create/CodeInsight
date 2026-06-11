#include <iostream>

int main()
{
using namespace std;

int a,b,c;
int now_num,counter=0;
cin>>a>>b>>c;

now_num=a;

while(now_num<=b)
{
if(c%now_num == 0)
counter++;

now_num++;
}

cout<<counter<<endl;
return 0;
}