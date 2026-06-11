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
const int mx= 1e5+123;
string n;
int a,b;
map<int,int>m;

void generate()
{
    for(int i=1;i<=9;i++)
        for(int j=i;j<=9;j++)
            m[i*j]++;
}

void _case_()
{
    cin >> a;
    if(m[a]) cout << "Yes\n";
    else cout << "No\n";
}



int main()
{
    optimize();
    generate();
    //_test_
    _case_();
}

///////////*  N A Y E M  *///////////