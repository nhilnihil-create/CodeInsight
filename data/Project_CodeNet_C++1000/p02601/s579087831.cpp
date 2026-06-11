#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb(x) push_back(x)
#define HAYAKU_HAYAKU ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    HAYAKU_HAYAKU; 
    int a,b,c,k;
    cin>>a>>b>>c;
    cin>>k; 
    while(b <= a){
        b = b * 2;
        k--;
    }
    while(c <= b){
        c = c * 2;
        k--;
    }
    k >= 0 ? cout<<"Yes" : cout<<"No";
}