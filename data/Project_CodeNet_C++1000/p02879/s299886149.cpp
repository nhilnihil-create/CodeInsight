#include <bits/stdc++.h>
using namespace std;

int main ()
{
int A,B;
cin>>A>>B;
if(A!=0&&A<=20&&B!=0&&B<=20){
    if(A<=9&&B<=9){
        cout<<A*B;
    }
    else{
        cout<<-1;
    }
}
return 0;
}