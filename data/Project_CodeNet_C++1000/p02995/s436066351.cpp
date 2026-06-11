#include <bits/stdc++.h>

using namespace std;
long long int a,b,c,d;
long long int judge(long long int);
long long int lcd(long long int,long long int);
long long int gcd(long long int ,long long int);

long long int judge(long long int x)
{
    if(x > b)
    {
        return 0;
    }
    if(a % x == 0)
    {
        return b / x - a / x + 1;
    }
    return b / x - a / x ;
}

long long int lcd(long long int x,long long int y)
{
   return x*y / gcd(x,y); 
}

long long int gcd(long long int x,long long int y)
{
    if(x < y)
    {
        long long int tmp = x;
        x = y;
        y = tmp;
    }
    long long int r = x % y;
    while(r > 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
  cin >> a >> b >> c >> d;
  long long int result = b - a + 1 - judge(c) - judge(d) + judge(lcd(c,d));
  cout << result << endl;
  return 0;
}