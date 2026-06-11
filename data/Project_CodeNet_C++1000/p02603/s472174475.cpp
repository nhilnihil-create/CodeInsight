#include <iostream>

using namespace std;

int main()
{long long j=1000,k=0;
long long n;
cin >> n;
int a[n];
for (int i=0;i<n;i++)
    cin >> a[i];
int l=0;
int y;
 for (int i=1;i<n;i++)
{
    if (a[i-1]<a[i])
    {
        k+=j/a[i-1];
    j=j%a[i-1];
    l=i-1;
  //  cout << 1 ;

    //y=a[i-1];
    }
     if (a[i]>a[i-1])
    {
        j+=k*a[i];
   // cout << j << endl;
        k=0;
    }

} int m=1;
for (int i=l;i<n;i++)
{
    m=max(m,a[i]);
}
j+=k*m;
cout << j <<endl;
    return 0;
}
