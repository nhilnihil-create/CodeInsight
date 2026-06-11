//بسم الله الرحمن الرحيم
///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define el << endl
#define PI 3.141592653589793238
#define _test_ int t; cin >> t; while(t--)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
ll gcd ( ll  a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }
int dx[]={0,0,+1,-1,+1,-1,-1,+1};
int dy[]={+1,-1,0,0,+1,-1,+1,-1};
///*......................*//* LET'S BEGIN (-_^) *//*............................///
const int mx= 2e6+123;
int n,a[mx],ans,m=1;

void _case_()
{
   string s,t;
   cin >> s >> t;
   for(int i=0;i<s.size();i++)
       if(s[i]==t[i]) ans++;
       cout << ans el;
}

int main()
{

    optimize();
    //_test_
    _case_();
    return 0;

}

///////////*  N A Y E M  *///////////