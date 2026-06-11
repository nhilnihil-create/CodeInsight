#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forp(a,b,c) for(int (a)=(b); (a)<(c); (a++))
#define form(a,b,c) for(int (a)=(b); (a)>(c); (a--))
#define fori(a,b) for(auto (a):(b))
#define pb(a) push_back(a)
#define INF ((unsigned) ~0)
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
 
int main()
{
    fastIO
    vector<char> vec1;
    vector<char> vec2;
    char c;
    while((c=getchar()) != '\n')
    {
        vec1.push_back(c);
    }
    while((c=getchar()) != EOF)
    {
        vec2.push_back(c);
    }
    int res=0;
    forp(i,0,vec1.size())
    {
        if(vec1[i]!=vec2[i]) res++;
    }
    cout<<res;
}