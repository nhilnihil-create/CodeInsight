#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
lli fun(lli h)
{
   if(h>1)
    return 2*(fun(h/2))+1;
   else
    return 1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli h;
    cin>>h;
    cout<<fun(h)<<"\n";
}