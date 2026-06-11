#include <bits/stdc++.h>
#define rep0(i,b) for(int i=0 ; i< b ;i++)
#define rep1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007
# define M_PI     3.14159265358979323846

using namespace std;


int main()
{
  string str1,str2;
  cin>>str1>>str2;

  if(str1 == str2.substr(0,str2.length()-1))
    cout<<"Yes";
  else
    cout<<"No";


  return 0 ;
}
