#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int A,B;
    cin>>A>>B;
 if(A!=B&&A>=0&&B>=0&&A<=1000000000&&B<=1000000000){   
    if(A%2==B%2){
        cout<<(A+B)/2;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
 }
    return 0;
}