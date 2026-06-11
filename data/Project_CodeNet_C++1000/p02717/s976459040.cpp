#include <bits/stdc++.h> 
using namespace std; 
void swap(int * num1, int * num2)
{
    int temp;
    temp = *num1;
    *num1= *num2;
    *num2= temp;
}
int main() 
{  int a,b,c;
   cin>>a>>b>>c;
   int sum;
   swap(a,b);
   swap(a,c);
    cout<<a<<" "<<b<<" "<<c<<" ";
    return 0; 
} 