#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
long long a,b,c,d; cin>>a>>b>>c>>d;
cout << max(b*d, max(b*c, max(a*d, a*c))) ;

}