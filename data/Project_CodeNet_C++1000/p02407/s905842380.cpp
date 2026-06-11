//reversing numbers

#include<iostream>
using namespace std;

int main()
{
int a[100] ;
int n;

cin >> n;

for(int i = 0; i < n; i++)
{
cin >> a[i];
}
for(int j = 1; j <= n; j++)
{
cout << a[n-j] ;
if(j==n){break;}
cout<<" ";
}
cout << endl;

return 0;
}