#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
string s ;
 cin>>s;

 int ans   = 0;

 int i = 0, j =s.size()-1;
 while(i<j)
 {
     if(s[i]!=s[j])
        ans++;
     i++;
     j--;
 }
 cout<<ans<<endl;
 return 0;
}
