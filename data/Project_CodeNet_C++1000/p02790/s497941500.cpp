#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    string s1(b, '0'+a);
    string s2(a, '0'+b);

    cout<<min(s1,s2)<<endl;
}
