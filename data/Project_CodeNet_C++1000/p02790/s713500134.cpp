#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define pf push_front
#define np next_permutation
#define pp prev_permutation
#define all(x) (x).begin(),(x).end()

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char x= n + '0';
    char y= m + '0';
    string a(m,x),b(n,y);
    cout<<min(a,b)<<endl;
    return 0;
}
