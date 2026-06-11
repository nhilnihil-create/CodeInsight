#include<bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) < (b) ? (b) : (a))
string str="a";
int n;
void fun(char a)
{
    if(str.size() ==  n)
    {
        cout<<str<<endl;
        return;
    }
    
    for(char x  ='a';x<=a+1;x++)
    {
        str+=x;
        fun(max(x,a));
        str.erase(str.end()-1);
        
    }
    
    
}


int main()
{

cin>>n;
fun('a');
}