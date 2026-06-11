#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
ll a[40001000];
//ll number[20],used[20];
int main()
{
  string a,b,c,d,s,t,e,f,g;
  cin>> s;
  a = "SAT";
  b="SUN";
  c="MON";
  d="TUE";
  e="WED";
  f="THU";
  g="FRI";
  if(a==s)
    cout << "1" << endl;
  if(b==s)
    cout << "7" << endl;
  if(c==s)
    cout << "6" << endl;
    if(d==s)
    cout << "5" << endl;
    if(e==s)
    cout << "4" << endl;
    if(f==s)
    cout << "3" << endl;
    if(g==s)
    cout << "2" << endl;
  //cout << a << endl;
    return 0;
}
