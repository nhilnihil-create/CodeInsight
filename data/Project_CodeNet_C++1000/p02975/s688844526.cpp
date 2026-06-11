#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <ll>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(ll i=0;i<n;i++)
#define pb      push_back
const ll mod=1e9+7;
void fast();
int main()
{
    int n;
    cin>>n;
    int a[n];
    ll x;
    loop(n){
        cin>>a[i];
        if(i)
            x^=a[i];
        else
            x=a[i];
    }
    if(!x)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
void fast(){
std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/// 20
/// 15 7 13 15 15 15 15 13 19
/*

*/
